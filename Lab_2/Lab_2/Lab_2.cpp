#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const int INF = 1000;

int** ReadFile(int& size);
void FindSize(int& size);
int** CreateMatrix(int&);
void FillMatrix(int**, int&);
void DeleteMatrix(int**, int&);
void PrintMatrix(int** Matrix, int& size, string str);
void Floyd_Warshall(int** Matrix, int size, int** p);
int MinValue(int a, int b);
int** CreateP(int** Matrix, int& size);
void IncrementP(int** p, int& size);
vector<string> delim(string str, char delim);


int main()
{
    int size;
    int** Matrix = ReadFile(size);
    int** p = CreateP(Matrix, size);
    Floyd_Warshall(Matrix, size, p);
    IncrementP(p, size);
    PrintMatrix(Matrix, size, "D(m): ");
    PrintMatrix(p, size, "P(ij): ");
    DeleteMatrix(Matrix, size);
    DeleteMatrix(p, size);
}


int** ReadFile(int& size) {
    FindSize(size);
    int** Matrix = CreateMatrix(size);
    cout << "Reading file..." << endl << endl;
    FillMatrix(Matrix, size);
    PrintMatrix(Matrix, size, "D(0): ");
    return Matrix;
}


void FindSize(int& size) {
    ifstream input("..\\iofiles\\input_15.txt");
    string currStr;
    size = -1;
    while (!input.eof()) {
        getline(input, currStr);
        size++;
        cout << size << endl;
    }

    input.close();
    input.clear();
}


int** CreateMatrix(int& size) {
    int** Matrix = new int* [size];
    for (int i = 0; i < size; i++)
    {
        Matrix[i] = new int[size];
    }
    return Matrix;
}


void PrintMatrix(int** Matrix, int& size, string str) {
    cout << str << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(6) << Matrix[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}


void FillMatrix(int** Matrix, int& size) {
    ifstream input("..\\iofiles\\input_15.txt");

    for (int i = 0; i < size; i++)
    {
        string currStr;
        getline(input, currStr);
        vector<string> tmp = delim(currStr, ' ');
        for (int j = 0; j < size; j++)
        {
            if (tmp[j] == "INF") {
                Matrix[i][j] = INF;
            }
            else {
                Matrix[i][j] = stoi(tmp[j]);
            }
        }
    }
    input.close();
    input.clear();
}


void DeleteMatrix(int** Matrix, int& size) {
    for (int i = 0; i < size; i++)
    {
        delete[] Matrix[i];
    }
    delete Matrix;
}


void Floyd_Warshall(int** Matrix, int size, int** p) {
    for (int k = 0; k < size; k++) {  //Run through all vertexes and find the shoutest route throgh vertex k
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (Matrix[i][k] && Matrix[k][j] && i != j)
                {
                    Matrix[i][j] = MinValue(Matrix[i][j], Matrix[i][k] + Matrix[k][j]);
                    // New weight is minimal between new sum of edges / old one
                    if (Matrix[i][j] == Matrix[i][k] + Matrix[k][j]) p[i][j] = k;
                }
            }
        }
    }
}


int MinValue(int a, int b) {
    int min;
    (a <= b) ? min = a : min = b;
    return min;
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


int** CreateP(int** graph, int& size) {
    int** Matrix = new int* [size];
    for (int i = 0; i < size; i++) 
        Matrix[i] = new int[size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (graph[i][j] != 0 && graph[i][j] != INF) Matrix[i][j] = i;
            else Matrix[i][j] = -1;
        }
    }
    return Matrix;
}


void IncrementP(int** p, int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (p[i][j] != -1) ++p[i][j];
        }
    }
}