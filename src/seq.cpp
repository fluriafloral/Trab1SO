#include "../headers/seq.h"
#include "../headers/func.h"
#include "../headers/matrix.h"

Matrix calculateMatrixProductSeq (Matrix matrix1, Matrix matrix2) {
    int resultN = matrix1.getN();
    int resultM = matrix2.getM();
    int restrictor = matrix1.getM();
    float** resultValues = new float*[resultN];
    
    try {
        if (matrix1.getM() == matrix2.getN()){
            for (int j = 0; j < resultN; j++) {
                resultValues[j] = new float[resultM];

                for (int k = 0; k < resultM; k++) {
                    resultValues[j][k] = 0;

                    for (int l = 0; l < restrictor; l++) {
                        resultValues[j][k] += matrix1.getValues()[l][k] * matrix2.getValues()[k][l];
                    }
                }
            }
        } else {
            throw 412;
        }
    } catch (int valueException) {
        cout << "operação inválida. matrix1.m != matrix2.n \n código do erro : " << valueException << endl;
    }

    return Matrix(resultN, resultM, resultValues);
}
 
int main() {
    string fileName1, fileName2;
    cin >> fileName1 >> fileName2;

    Matrix matrix1 = readFile(fileName1);
    Matrix matrix2 = readFile(fileName2);

    chrono::system_clock::time_point start = chrono::high_resolution_clock::now();
    Matrix result = calculateMatrixProductSeq(matrix1, matrix2);
    chrono::system_clock::time_point end = chrono::high_resolution_clock::now();

    const auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(end - start);
   
    string resultFileName = generateFileName("result-" + to_string(result.getN()) + "x" + to_string(result.getN()));
    createResultFile(resultFileName, result, elapsedTime);

    return 0;

}