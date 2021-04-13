#include "Coloring.h"

void Result(int* ColorsArr, int VertexAmount)
{
    int max = 0;
    for (int i = 0; i < VertexAmount; i++)
        if (max < ColorsArr[i])
            max = ColorsArr[i];

    cout << "Сhromatic number: " << max << endl << endl;

    vector<string> names = { "Бричанский","Окницкий","Единецкий","Дондюшанский","Рышканский","Дрокиевский","Сорокский","Глодянский",
                            "Бельцы","Флорештский","Сынжерейский","Фалештский","Шолданешский", "Резинский", "Телештский" };

    cout << " Graph coloring: " << endl;
    for (int i = 0; i < VertexAmount; i++)
        cout << setw(15) << names[i] << setw(3) << ColorsArr[i] << endl;
    cout << endl;
}

bool isSafe(int v, int** Matrix, int* ColorsArr, int CurrColor, int VertexAmount)
{
    for (int i = 0; i < VertexAmount; i++)
        if (Matrix[v][i] && (CurrColor == ColorsArr[i] || CurrColor == -1))
            return false;
    return true;
}

bool Backtracking(int** Matrix, int* ColorsArr, int CurrVert, int VertexAmount, map<int, vector<int>> possibleColors)
{
    if (CurrVert == VertexAmount)
        return true;

    for (int i = possibleColors[CurrVert][0]; i < possibleColors[CurrVert].size(); i++) {
        if (isSafe(CurrVert, Matrix, ColorsArr, i, VertexAmount))
        {
            ColorsArr[CurrVert] = i;

            for (int k = 0; k < VertexAmount; k++) {
                if (Matrix[CurrVert][k] != 0) {
                    int colorUsedInNode = ColorsArr[CurrVert];
                    possibleColors[k][colorUsedInNode] = -1;
                }
            }

            if (Backtracking(Matrix, ColorsArr, CurrVert + 1, VertexAmount, possibleColors))
                return true;

            ColorsArr[CurrVert] = 0;
        }
    }
    return false;
}

bool ColoringAlgo(int** Matrix, int CurrentColor, int VertexAmount)
{
    int* ColorsArr = new int[VertexAmount];
    for (int i = 0; i < VertexAmount; i++) ColorsArr[i] = 0;

    //Heuristic
    vector<int> allColors;
    for (int i = 0; i < CurrentColor; i++) allColors.push_back(i + 1);
    map<int, vector<int>> possibleColors;
    for (int i = 0; i < VertexAmount; i++) possibleColors[i] = allColors;

    // Backtracking
    if (!Backtracking(Matrix, ColorsArr, 0, VertexAmount, possibleColors)) return false;

    Result(ColorsArr, VertexAmount);
    delete[] ColorsArr;
    return true;
}

int FindChrom(int** Matrix, int VertexAmount)
{
    int* chrom = new int[VertexAmount];
    for (int i = 0; i < VertexAmount; i++)
    {
        chrom[i] = 0;
    }
    int max = 0;
    for (int i = 0; i < VertexAmount; i++)
    {
        for (int j = 0; j < VertexAmount; j++)
        {
            if (Matrix[i][j] == 1) chrom[i]++;
        }
        if (chrom[i] > max) max = chrom[i];
    }

    delete[] chrom;
    return max + 1;
}