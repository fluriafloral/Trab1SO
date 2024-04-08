#include "../headers/func.h"

bool fileExists(string fileName) {
    return filesystem::exists(fileName);
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

    return "files/" + prefix + ".txt";
}

bool dirExists(string dirName) {
    return filesystem::exists(dirName) && filesystem::is_directory(dirName);
}

string generateDirName(string prefix) {
    if(dirExists("files/" + prefix)) {
        int counter = 1;
        prefix += "-" + to_string(counter);

        while (dirExists("files/" + prefix)) {  
            prefix.pop_back();
            counter++;
            prefix += to_string(counter);
        }
    }
    filesystem::create_directory("files/" + prefix);
    return "files/" + prefix;
}

Matrix readFile (string fileName) {
    ifstream file(fileName);
    int n, m;
    double** values = nullptr;

    file >> n >> m;
    values = new double*[n];

    for (int j = 0; j < n; j++){
        values[j] = new double[m];

        for (int k = 0; k < m; k++) {
            file >> values[j][k];
        }
    }

    file.close();
    return Matrix(n, m, values);
}

void createMatrixFile(string fileName, Matrix matrix) {
    ofstream file(fileName);
    
    file << matrix.getN() << " " << matrix.getM() << "\n";

    for (int j = 0; j < matrix.getN(); j++) {
        for (int k = 0; k < matrix.getM(); k++) {
            file << matrix.getValues()[j][k] << " ";
        }
        file << "\n";
    } 

    cout << "matriz randômica " + fileName + " armazenada com sucesso" << endl;
    file.close();
}

void createResultFile(string fileName, Matrix result, chrono::nanoseconds timeElapsed) {
    ofstream file(fileName);

    file << result.getN() << " " << result.getM() << "\n";

    for (int j = 0; j < result.getN(); j++) {
        for (int k = 0; k < result.getM(); k++) {
            file << "c[" << j+1 << "][" << k+1 << "] = " << result.getValues()[j][k] << "\n";
        }
    }
    file << to_string(timeElapsed.count());
    
    cout << "resultado do produto " + fileName + " armazenado com sucesso" << endl;
    file.close();
}