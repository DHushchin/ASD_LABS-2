#include "ReadFile.h"

using namespace std;

int** ReadFile(int& size) {
    FindSize(size);
    int** Matrix = CreateMatrix(size);
    cout << "Reading file..." << endl << endl;
    FillMatrix(Matrix, size);
    PrintMatrix(Matrix, size, "Adjacency matrix: ");
    return Matrix;
}

void FindSize(int& size) {
    ifstream input("..\\Moldova.txt");
    string currStr;
    size = 0;
    while (!input.eof()) {
        getline(input, currStr);
        size++;
    }
    input.close();
    input.clear();
}

int** CreateMatrix(int size) {
    int** Matrix = new int* [size];
    for (int i = 0; i < size; i++)
        Matrix[i] = new int[size];
    return Matrix;
}

void PrintMatrix(int** Matrix, int& size, string str) {
    cout << str << endl;
    cout << "   ";
    for (int i = 1; i <= size; i++)
        cout << setw(3) << i;
    cout << endl << endl;
    for (int i = 0; i < size; i++)
    {
        cout << setw(2) << i + 1 << "  ";
        for (int j = 0; j < size; j++)
            cout << setw(2) << Matrix[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}

void FillMatrix(int** Matrix, int size) {
    ifstream input("..\\Moldova.txt");

    for (int i = 0; i < size; i++)
    {
        string currStr;
        getline(input, currStr);
        vector<string> tmp = delim(currStr, ' ');
        for (int j = 0; j < size; j++)
            Matrix[i][j] = stoi(tmp[j]);
    }
    input.close();
    input.clear();
}

void DeleteMatrix(int** Matrix, int size) {
    for (int i = 0; i < size; i++)
        delete[] Matrix[i];
    delete Matrix;
}

vector<string> delim(string str, char delim) {
    int start, end = 0;
    vector<string> vect;
    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        int length = end - start;
        if (length == 0) continue;

        string word = string(str, start, length);
        vect.push_back(word);
    }
    return vect;
}