#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

void Result(int* color, int VertexAmount);
bool isSafe(int v, int** graph, int* color, int c, int VertexAmount);
bool Backtracking(int** graph, int* color, int v, int VertexAmount, map<int, vector<int>> possibleColors);
bool ColoringAlgo(int** graph, int CurrentColor, int VertexAmount);
int FindChrom(int** Matrix, int VertexAmount);