#ifndef MATRIX_H
#define MATRIX_H

class Matrix {

    private:

        int n;
        int m;
        float** values;

    public:

        Matrix(int n, int m, float** values);
        int getN();
        int getM();
        float** getValues();

};

#endif