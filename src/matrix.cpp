#include "../headers/matrix.h"

Matrix::Matrix(int n, int m) {
    this->n = n;
    this->m = m;

    this->values = new double*[n];
    for (int j = 0; j < n; j++) {
        values[j] = new double[m];
    }
}

Matrix::Matrix(int n, int m, double** values) {
    this->n = n;
    this->m = m;
    this->values = values;
}

int Matrix::getN() {
    return n;
};

int Matrix::getM() {
    return m;
};

double** Matrix::getValues() {
    return values;
};
