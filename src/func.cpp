#include "../headers/func.h"

bool fileExists(string fileName) {
    ifstream f(fileName);
    return f.good();
}

string generateFileName(string prefix) {
    if (fileExists("files/" + prefix + ".txt")) {
        int counter = 1;
        prefix += "-" + to_string(counter);

        while (fileExists("files/" + prefix  + ".txt")) {  
            prefix.pop_back();
            counter++;
            prefix += to_string(counter);
        }
    }
    string fileName = "files/" + prefix + ".txt";

    return fileName;
}

Matrix readFile (string fileName) {
    ifstream file(fileName);
    int n, m;
    float** values = nullptr;

    file >> n >> m;
    values = new float*[n];

    for (int j = 0; j < n; j++){
        values[j] = new float[m];

        for (int k = 0; k < m; k++) {
            file >> values[j][k];
        }
    }

    file.close();
    return Matrix(n, m, values);
}

void createMatrixFile(string fileName, Matrix matrix) {
    ofstream file(fileName);
    
    file << matrix.getN() << matrix.getM();

    for (int j = 0; j < matrix.getN(); j++) {
        for (int k = 0; k < matrix.getM(); k++) {
            file << matrix.getValues()[j][k] << " ";
        }
        file << "\n";
    } 

    cout << "matriz randômica " + fileName + " armazenada com sucesso" << endl;
    file.close();
}

void createResultFile(string fileName, Matrix result, chrono::milliseconds timeElapsed) {
    ofstream file(fileName);

    int n, m;
    file << n << m;

    for (int j = 0; j < result.getN(); j++) {
        for (int k = 0; k < result.getM(); k++) {
            file << "c" << j << k << " " << result.getValues()[j][k] << "\n";
        }
    }
    file << to_string(timeElapsed.count());
    
    cout << "resultado do produto " + fileName + " armazenado com sucesso" << endl;
    file.close();
}