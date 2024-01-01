#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

void printMatrix(int matrix[100][100], int rows, int cols){
    cout << "Ma trận :" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void readAndSumMatrixFile(string filePath, int (&matrix)[100][100], int &rows, int &cols, int &sumPrimes){
    ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        cout << "Không thể mở file." << endl;
        return;
    }
    inputFile >> rows >> cols;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            inputFile >> matrix[i][j];
            if(isPrime(matrix[i][j])){
                sumPrimes += matrix[i][j];
            }
        }
    }

    inputFile.close();
    
}

void writeResultToFile(string& filePath, int sumPrimes) {
    std::ofstream outputFile(filePath);

    if (!outputFile.is_open()) {
        std::cerr << "Không thể mở file." << std::endl;
        return;
    }

    outputFile << "Tong cac so nguyen to: " << sumPrimes << std::endl;

    outputFile.close();
}

int main() {
    string filePathData = "data.txt";
    string filePathResult = "result.txt";
    int rows = 0, cols = 0, sumPrimes = 0;
    int matrix[100][100];
    readAndSumMatrixFile(filePathData, matrix, rows, cols, sumPrimes);
    printMatrix(matrix, rows, cols);
    writeResultToFile(filePathResult, sumPrimes);
    return 0;
}
