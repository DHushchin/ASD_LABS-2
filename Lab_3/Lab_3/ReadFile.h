#pragma once

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

int** ReadFile(int& size);
void FindSize(int& size);
int** CreateMatrix(int size);
void FillMatrix(int** Matrix, int size);
void DeleteMatrix(int** Matrix, int size);
void PrintMatrix(int** Matrix, int& size, string str);
vector<string> delim(string str, char delim);
