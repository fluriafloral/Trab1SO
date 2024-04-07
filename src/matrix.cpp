#include "../headers/matrix.h"

    Matrix::Matrix(int n, int m, float** values) {
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

    float** Matrix::getValues() {
        return values;
    };
