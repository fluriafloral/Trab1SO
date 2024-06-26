#include "../headers/aux.h"
#include "../headers/func.h"
#include "../headers/matrix.h"

Matrix generateMatrix(int n, int m) {
    double** values = new double*[n];

    for (int j = 0; j < n; j++) {
        values[j] = new double[m];

        for (int k = 0; k < m; k++) {
            values[j][k] = static_cast<double> (rand()) / static_cast<double> (RAND_MAX/10); // gera umdouble aleatório entre 0.0 e 10.0
        }
    }
    
    return Matrix(n, m, values);
}
 
int main() {
    int n1, m1, n2, m2;
    cin >> n1 >> m1 >> n2 >> m2;

    string fileName1 = generateFileName("generatedMatrices/" + to_string(n1) + "x" + to_string(m1));
    createMatrixFile(fileName1, generateMatrix(n1, m1));

    string fileName2 = generateFileName("generatedMatrices/" + to_string(n2) + "x" + to_string(m2));
    createMatrixFile(fileName2, generateMatrix(n2, m2));

    return 0;
}