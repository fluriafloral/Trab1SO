#include "../headers/aux.h"
#include "../headers/func.h"
#include "../headers/matrix.h"

Matrix generateMatrix(int n, int m) {
    random_device randomDevice;
    mt19937 generator(randomDevice());
    uniform_real_distribution<> distribution(0.0, 10.0);

    float** values = new float*[n];

    for (int j = 0; j < n; j++) {
        values[j] = new float[m];

        for (int k = 0; k < m; k++) {
            values[j][k] = distribution(generator); // gera um float aleatório entre 0.0 e 10.0
            
            if (values[j][k] > 10.0) {
                values[j][k] = distribution(generator);
            }
        }
    }
    
    return Matrix(n, m, values);
}
 
int main() {
    int n1, m1, n2, m2;
    cin >> n1 >> m1 >> n2 >> m2;

    string fileName1 = generateFileName(to_string(n1) + "x" + to_string(m1));
    createMatrixFile(fileName1, generateMatrix(n1, m1));

    string fileName2 = generateFileName(to_string(n2) + "x" + to_string(m2));
    createMatrixFile(fileName2, generateMatrix(n2, m2));

    return 0;
}