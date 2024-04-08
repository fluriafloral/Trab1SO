#include "../headers/threads.h"

void multiplyRows(Matrix result, Matrix matrix1, Matrix matrix2, int startRow, int endRow) {
    chrono::system_clock::time_point start = chrono::high_resolution_clock::now();
    for(int j = startRow; j < endRow; j++) {
        for(int k = 0; k < result.getM(); k++) {
            for(int l = 0; l < matrix1.getM(); l++) {
                result.getValues()[j][k] += matrix1.getValues()[j][l] * matrix2.getValues()[l][j];
            }
        }
    }
    chrono::system_clock::time_point end = chrono::high_resolution_clock::now();

    const auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(end - start);

    string dirPath = generateDirName("resultThreads-" + to_string(result.getN()) + "x" + to_string(result.getM()) + "/");
    string filePath = generateFileName(dirPath + "resultThreads-" + to_string(result.getN()) + "x" + to_string(result.getN()));

    createResultFile(generateFileName(filePath), result, elapsedTime);
}

int main() {
    string matrixFile1, matrixFile2;
    int p;

    cin >> matrixFile1 >> matrixFile2 >> p;

    Matrix matrix1 = readFile(matrixFile1);
    Matrix matrix2 = readFile(matrixFile2);
    Matrix result(matrix1.getN(), matrix2.getM());

    int elementsQuant = result.getN() * result.getM();
    int threadsQuant = elementsQuant / p;

    if(p == 0 || p > elementsQuant) {
        cout << "valor de p inválido" << endl;
        return -1;
    }

    thread threads[threadsQuant];
    int subMatrixN = result.getN() / threadsQuant;
    int startRow = 0;

    for(int j = 0; j < threadsQuant; j++) {
        int endRow = j == threadsQuant - 1? result.getN() : startRow + subMatrixN;
        threads[j] = thread(multiplyRows, result, matrix1, matrix2, startRow, endRow);
        startRow = endRow;
    }

    for (int j = 0; j < threadsQuant; j++) {
        threads[j].join();
    }

    return 0;
}