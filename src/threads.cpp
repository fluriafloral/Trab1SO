#include "../headers/threads.h"

void calculateResultElement(double** resultValues, Matrix matrix1, Matrix matrix2, int row, int col, int restrictor) {
    for(int j = 0; j < restrictor; j++) {
            resultValues[row][col] += matrix1.getValues()[row][j] * matrix2.getValues()[j][col];
    }
}

void calculateResultElements(double** resultValues, Matrix matrix1, Matrix matrix2, int row, int col, int restrictor, int elementsQuant) {
    for(int j = 0; j < elementsQuant; j++) {
        calculateResultElement(resultValues, matrix1, matrix2, row, col, restrictor);
        col++;
        if(col >= matrix2.getM() - 1) {
            row++;
            col = 0;
        }
    }
}

void calculateMatrixProductThreads(Matrix matrix1, Matrix matrix2, int p) {
    int resultN = matrix1.getN();
    int resultM = matrix2.getM();
    int restrictor = matrix1.getM();

    double** resultValues = new double*[resultN];
    for(int j = 0; j < resultN; j++) {
        resultValues[j] = new double[resultM];
    }

    int elementsQuant = resultN * resultM;
    int threadsQuant = elementsQuant / p;
    thread threads[threadsQuant];
    int initialRow = 0, initialCol = 0;

    for(int j = 0; j < threadsQuant; j++) {

        threads[j] = thread(calculateResultElements, resultValues, matrix1, matrix2, initialRow, initialCol, restrictor, (j == threadsQuant - 1)? elementsQuant % p : p);
    }

    string resultDir = generateDirName("resultThreads/" + to_string(matrix1.getN()) + "x" + to_string(matrix2.getM()) + "(p=" + to_string(p) + ")");

    for(int j = 0; j < threadsQuant; j++) {
        chrono::system_clock::time_point start = chrono::high_resolution_clock::now();
        threads[j].join();
        chrono::system_clock::time_point end = chrono::high_resolution_clock::now();
        chrono::nanoseconds elapsedTime = chrono::duration_cast<chrono::nanoseconds>(end - start);

        string filePath = generateFileName(resultDir + to_string(matrix1.getN()) + "x" + to_string(matrix2.getM()));
        int startRow = (j * p) / matrix2.getM();
        int startCol = (j * p) % matrix2.getM();
        int endRow = (j == threadsQuant - 1)? (matrix1.getN() * matrix2.getM()) / matrix2.getM() : ((j+1) * p) / matrix2.getM();
        int endCol = (j == threadsQuant - 1)? (matrix1.getN() * matrix2.getM()) % matrix2.getM() : ((j+1) * p) % matrix2.getM();
        createSubMatrixResultFile(filePath, Matrix(resultN, resultM, resultValues), startRow, endRow, startCol, endCol, elapsedTime);
    }
}

int main() {
    string matrixFile1, matrixFile2;
    int p;

    cin >> matrixFile1 >> matrixFile2 >> p;

    if(!fileExists(matrixFile1) || !fileExists(matrixFile2)) {
        cout << "arquivo(s) não encontrados" << endl;
        return -1;
    }

    Matrix matrix1 = readFile(matrixFile1);
    Matrix matrix2 = readFile(matrixFile2);

    if(p <= 0 || p > matrix1.getN() * matrix2.getM()) {
        cout << "valor de p inválido" << endl;
        return -1;
    }

    calculateMatrixProductThreads(matrix1, matrix2, p);

    return 0;
}