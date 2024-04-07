#include <iostream> // string
#include <fstream> // ifstream
#include <chrono> // milliseconds
#include "../headers/matrix.h" 

using namespace std;

bool fileExists(string fileName);
string generateFileName(string prefix);
Matrix readFile (string fileName);
void createMatrixFile(string fileName, Matrix matrix);
void createResultFile(string fileName, Matrix result, chrono::nanoseconds timeElapsed);