#include <iostream>
#include <iomanip>
#include <stack>

using namespace std;

int** init_matr(int n, int m);
void print_matr(int** matr, int n, int m);
void delete_matr(int** matr, int n);
void Terri_algo(int** matr, int n, int m, int beg_v, int end_v, stack <int>& res, bool& flag);
void print_stack(stack<int> s);
int find_vetr(int** matr, int n, int j, stack <int> res);
bool in_stack(stack <int> s, int v);

int main() {
    int vetr, edge;
    cout << "Enter number of vetrex: "; cin >> vetr;
    cout << "Enter number of edges: "; cin >> edge;

    int** matr = init_matr(vetr, edge);
    print_matr(matr, vetr, edge);

    int beg_v, end_v;
    cout << "Enter beginning vetrex: "; cin >> beg_v;
    cout << "Enter ending vetrex: "; cin >> end_v;
    beg_v--; end_v--;

    stack <int> res;
    bool flag = false;
    Terri_algo(matr, vetr, edge, beg_v, end_v, res, flag);
    delete_matr(matr, vetr);
    system("pause >> void");
    return 0;
}


int** init_matr(int n, int m)
{
    int** matr = new int* [n];
    cout << endl;
    for (int i = 0; i < n; i++) {
        matr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cout << "Vetrex: " << i + 1 << '\t' << "Edge: " << j + 1 << " - ";
            cin >> matr[i][j];
        }
        cout << endl;
    }
    return matr;
}

void print_matr(int** matr, int n, int m)
{
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(3) << matr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void delete_matr(int** matr, int n)
{
    for (int i = 0; i < n; i++) delete[]matr[i];
    delete[]matr;
}

void Terri_algo(int** matr, int n, int m, int beg_v, int end_v, stack <int>& res, bool& flag)
{
    if (beg_v == end_v)
    {
        res.push(beg_v);
        cout << "Route: ";
        print_stack(res);
        flag = true;
    }
    else
    {
        for (int j = 0; j < m; j++) {
            if (matr[beg_v][j] == 1)
            {
                if (in_stack(res, beg_v) == false) res.push(beg_v);
                int vetr = find_vetr(matr, n, j, res);
                if (vetr != -1) Terri_algo(matr, n, m, vetr, end_v, res, flag);
            }
        }
        if (flag == false) res.pop();
    }
}

void print_stack(stack<int> s)
{
    if (s.empty()) return;
    int x = s.top();
    s.pop(); // Pop the top element of the stack
    print_stack(s); // Recursively call the function print_stack
    cout << x + 1 << ' '; //Print the stack element starting from the bottom
    s.push(x); // Push the same element onto the stack to preserve the order
}

int find_vetr(int** matr, int n, int edge, stack <int> res)
{
    int v = -1;
    for (int i = 0; i < n; i++)
        if (matr[i][edge] == 1 && in_stack(res, i) == false) {
            v = i;
            break;
        }
    return v;
}

bool in_stack(stack <int> s, int v)
{
    bool in_flag = false;
    while (s.empty() == false) {
        if (s.top() == v) {
            in_flag = true;
            break;
        }
        s.pop();
    }
    return in_flag;
}
