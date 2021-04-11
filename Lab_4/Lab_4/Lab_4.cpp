#include <iostream>

using namespace std;

class Stack {
private:
    int* arr;
    int capacity;
    int size;
public:
    Stack();
    Stack(int size);
    Stack(const Stack& other);
    ~Stack();
    void push(int x);
    void pop();
    bool empty();
    int top();
};

void printRange(Stack stack, int max, int min);
int findMin(Stack stack);
int findMax(Stack stack);

int main()
{
    int size;
    cout << "Enter amount of numbers: "; cin >> size;
    Stack S;
    for (int i = 0; i < size; i++) {
        int num;
        cout << "Enter number: "; cin >> num;
        S.push(num);
    }
    int max = findMax(S);
    int min = findMin(S);
    printRange(S, max, min);
    system("pause");
    return 0;
}


void printRange(Stack stack, int max, int min) {
    bool flag = true;
    while (flag && !stack.empty()) {
        if (stack.top() == max)
        {
            cout << endl;
            while (stack.top() != min) {
                cout << stack.top() << '\t';
                stack.pop();
            }
            cout << stack.top();
            flag = false;
        }
        else if (stack.top() == min)
        {
            cout << endl;
            while (stack.top() != max) {
                cout << stack.top() << '\t';
                stack.pop();
            }
            cout << stack.top();
            flag = false;
        }
        stack.pop();
    }
    cout << endl;
}

int findMin(Stack stack) {
    int min = INT_MAX;
    while (!stack.empty()) {
        if (stack.top() < min) min = stack.top();
        stack.pop();
    }
    return min;
}

int findMax(Stack stack) {
    int max = INT_MIN;
    while (!stack.empty()) {
        if (stack.top() > max) max = stack.top();
        stack.pop();
    }
    return max;
}

Stack::Stack() { // конструктор
    size = 3;
    arr = new int[size];
    capacity = -1;
}

Stack::Stack(int size) { // конструктор
    this->size = size;
    arr = new int[size];
    capacity = -1;
}

Stack::Stack(const Stack& other) { // конструктор копирования
    this->size = other.size;
    this->capacity = other.capacity;
    this->arr = new int[size];
    if (capacity >= 0) {
        for (int i = 0; i < other.capacity; i++) {
            this->arr[i] = other.arr[i];
        }
    }
}

Stack::~Stack() { // деструктор
    delete[] arr;
}

void Stack::push(int value) {
    if (capacity == size - 1) {
        int* new_arr = new int[size * 2 + 1];
        for (int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        this->arr = new_arr;
        
        for (int i = 0; i < size; i++) {
            arr[i] = new_arr[i];
        }
        size = size * 2 + 1;
    }
    capacity++;
    arr[capacity] = value;
}

void Stack::pop() {
    if (capacity >= 0) {
        //arr[capacity] = 0;
        --capacity;
    }
    else {
        cout << "It's empty";
    }
}

bool Stack::empty() {
    return (capacity == 0);
}

int Stack::top() {
    return arr[capacity - 1];
}