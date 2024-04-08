#ifndef MATRIX_H
#define MATRIX_H

class Matrix {

    private:

        int n;
        int m;
        double** values;

    public:

        Matrix(int n, int m);
        Matrix(int n, int m, double** values);
        int getN();
        int getM();
        double** getValues();
};

#endif