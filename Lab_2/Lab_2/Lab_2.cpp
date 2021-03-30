#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#define INF 1000
using namespace std;

int** ReadFile(int& size);
void FindSize(int& size);
int** CreateMatrix(int&);
void FillMatrix(int**, int&);
void DeleteMatrix(int**, int&);
void PrintMatrix(int** Matrix, int& size);
void Output(int** Matrix, int size);
void Floyd_Warshall(int** Matrix, int size);
int min_value(int a, int b);
vector<string> delim(string str, char delim);


int main()
{
    int size;
    int** Matrix = ReadFile(size);
    Floyd_Warshall(Matrix, size);
    PrintMatrix(Matrix, size);
    Output(Matrix, size);
    DeleteMatrix(Matrix, size);
}


int** ReadFile(int& size) {
    FindSize(size);
    int** Matrix = CreateMatrix(size);
    cout << "Reading file..." << endl << endl;
    FillMatrix(Matrix, size);
    PrintMatrix(Matrix, size);
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

void PrintMatrix(int** Matrix, int& size) {
    cout << "Weight matrix:" << endl;
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

void Output(int** Matrix, int size)
{
    ofstream output("..\\iofiles\\output.txt");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            output << Matrix[i][j] << ' ';
        }
        output << endl;
    }
    output.close();
    cout << "Saved to output.txt" << endl;
}

void Floyd_Warshall(int** matrix, int size) {
    for (int k = 0; k < size; k++) {  //Run through all vertexes and find the shoutest route throgh vertex k
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i][k] && matrix[k][j] && i != j)
                    matrix[i][j] = min_value(matrix[i][j], matrix[i][k] + matrix[k][j]); 
                    // New weight is minimal between new sum of edges / old one
            }
        }
    }
}

int min_value(int a, int b) {
    int min;
    (a < b) ? min = a : min = b;
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