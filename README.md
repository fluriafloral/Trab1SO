# Trab1SO
Projeto da primeira unidade de Sistemas operacionais em C++

## Instruções para rodar (cmd)

acessar o diretório Trab1SO

### Gerar matrizes
g++ -std=c++17 src/aux.cpp src/func.cpp src/matrix.cpp -o bin/aux
./bin/aux

### Multiplicação sequencial
g++ -std=c++17 src/seq.cpp src/func.cpp src/matrix.cpp -o bin/seq
./bin/seq

### Multiplicação paralela com threads
g++ -std=c++17 src/threads.cpp src/func.cpp src/matrix.cpp -o bin/threads
./bin/threads