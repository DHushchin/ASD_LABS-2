#include "ReadFile.h"
#include "Coloring.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int size;
    int** Matrix = ReadFile(size);
    int VertexAmount = 15;
    int ChromNum = FindChrom(Matrix, VertexAmount);
    ColoringAlgo(Matrix, ChromNum, VertexAmount);
    DeleteMatrix(Matrix, size);
    system("pause");
    return 0;
}