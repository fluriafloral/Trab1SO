#include <iostream> // string
#include <fstream> // ofstream
#include <filesystem> // exists, is_directory
#include <chrono> // milliseconds
#include "../headers/matrix.h" 

using namespace std;

bool fileExists(string fileName);
string generateFileName(string prefix);
bool dirExists(string dirName);
string generateDirName(string prefix);
Matrix readFile (string fileName);
void createMatrixFile(string fileName, Matrix matrix);
void createResultFile(string fileName, Matrix result, chrono::nanoseconds timeElapsed);
void createSubMatrixResultFile(string fileName, Matrix result, int startRow, int endRow, int startCol, int endCol, chrono::nanoseconds elapsedTime);