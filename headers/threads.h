#include <iostream> // string
#include <fstream> // ifstream
#include <thread> // thread
#include <chrono> // now, time_point, duration cast
#include "func.h"

using namespace std;

void multiplyRows(Matrix result, Matrix matrix1, Matrix matrix2, int startRow, int endRow);