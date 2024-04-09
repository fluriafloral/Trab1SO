#include <iostream> // string
#include <fstream> // ifstream
#include <thread> // thread
#include <chrono> // now, time_point, duration cast
#include "func.h"

using namespace std;

void calculateResultElement(double** resultValues, Matrix matrix1, Matrix matrix2, int row, int col, int restrictor);
void calculateResultElements(double** resultValues, Matrix matrix1, Matrix matrix2, int row, int col, int restrictor, int elementsQuant);
void calculateMatrixProductThreads(Matrix matrix1, Matrix matrix2, int p);