#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int** ReadFile(int& rows, int& columns);
void FindSize(ifstream&, int&, int&);
int** CreateMatrix(int&, int&);
void FillMatrix(ifstream&, int**, int&, int&);
void DeleteMatrix(int**, int&);
void PrintMatrix(int** Matrix, int& rows, int& columns);
void Output(int** Matrix, int rows, int columns);

int main()
{
    int rows, columns;
    int** Matrix = ReadFile(rows, columns);
    Output(Matrix, rows, columns);
    DeleteMatrix(Matrix, rows);
}


int** ReadFile(int& rows, int& columns) {
    ifstream input("..\\iofiles\\input.txt");
    FindSize(input, rows, columns);
    int** Matrix = CreateMatrix(rows, columns);
    input.close();
    input.clear();
    input.open("..\\iofiles\\input.txt");
    FillMatrix(input, Matrix, rows, columns);
    PrintMatrix(Matrix, rows, columns);
    input.close();
    return Matrix;
}

void FindSize(ifstream& input, int& rows, int& columns) {
    string currStr;
    rows = 0;
    while (!input.eof()) {
        getline(input, currStr);
        columns = currStr.length();
        rows++;
    }
}

int** CreateMatrix(int& rows, int& columns) {
    int** Matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        Matrix[i] = new int[columns];
    }
    return Matrix;
}

void PrintMatrix(int** Matrix, int& rows, int& columns) {
    cout << "Inputted this problem:" << endl << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << Matrix[i][j];
        }
        cout << endl;
    }
}

void FillMatrix(ifstream& input, int** Matrix, int& rows, int& columns) {
    for (int i = 0; i < rows; i++)
    {
        string currStr;
        getline(input, currStr);
        for (int j = 0; j < columns; j++)
        {
            Matrix[i][j] = currStr[j] - '0';
        }
    }
}

void DeleteMatrix(int** Matrix, int& rows) {
    for (int i = 0; i < rows; i++)
    {
        delete[] Matrix[i];
    }
    delete Matrix;
}

void Output(int** Matrix, int rows, int columns)
{
    ofstream output("..\\iofiles\\output.txt");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            output << Matrix[i][j];
        }
        output << endl;
    }
    output.close();
    cout << "Saved to output.txt" << endl;
}