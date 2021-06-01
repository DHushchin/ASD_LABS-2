#include "HashTable.hpp"

using namespace std;

Cell::Cell() {
    key = value = "";
    isDeleted = false;
}


Cell::Cell(string key, string value)
{
    this->key = key;
    this->value = value;
    isDeleted = false;
}


Cell::Cell(const Cell& other) {
    this->key = key;
    this->value = value;
}


void Cell::setKey(string key)
{
    this->key = key;
}


void Cell::setValue(string value)
{
    this->value = value;
}


void Cell::setDeleted(bool isDeleted) {
    this->isDeleted = isDeleted;
}


string Cell::getKey()
{
    return key;
}


string Cell::getValue()
{
    return value;
}


bool Cell::getDeleted() {
    return isDeleted;
}


HashTable::HashTable() {
    TableSize = 1;
    NumberOfElements = Comparisons = 0;
    charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    Table = new Cell*[TableSize];
    for (int i = 0; i < TableSize; i++) 
        Table[i] = NULL;
}


HashTable::HashTable(int size)
{
    NumberOfElements = Comparisons = 0;
    this->TableSize = size;
    charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    Table = new Cell*[TableSize];
    for (int i = 0; i < TableSize; i++)
        Table[i] = NULL;
}


int HashTable::getSize() {
    return TableSize;
}


int HashTable::getElements() {
    return NumberOfElements;
}


int HashTable::getComparisons() {
    return Comparisons;
}


string HashTable::StringGenerator() {
    string result;
    int length = rand() % 200;
    for (int i = 0; i < length; i++)
        result += charset[rand() % charset.size()];
    return result;
}


unsigned int HashTable::PearsonHashing(string str)
{
    vector <unsigned char> T(256);
    for (int i = 0; i < 256; i++)
        T[i] = i - '0';
    unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(T.begin(), T.end(), default_random_engine(seed));

    unsigned int hash = 0;
    unsigned int current_hash = 0;
    for (int i = 0; i < 8; ++i) {
        current_hash = T[(str[0] + i) % 256];
        for (unsigned char symbol : str)
            current_hash = T[current_hash ^ symbol];
        hash += current_hash;
    }

    return hash % TableSize;
}


void HashTable::insert(string value)
{
    if (TableSize <= NumberOfElements) 
        resize();
    unsigned int hash = PearsonHashing(value);
    while (Table[hash] != NULL)
        ++hash %= TableSize;
    Table[hash] = new Cell(to_string(hash), value);
    NumberOfElements++;
}


void HashTable::print()
{
    cout << endl;
    for (int i = 0; i < TableSize; i++)
        if (Table[i] != NULL && !Table[i]->getDeleted())
            cout << Table[i]->getKey() + "  " + Table[i]->getValue() << endl;
    cout << endl;
}


Cell* HashTable::search(string key)
{
    Comparisons = 0;
    int hash = PearsonHashing(key);
    for (int i = 0; i < TableSize; i++)
    {
        if (Table[hash] != NULL && !Table[hash]->getDeleted()) {
            if (Table[hash]->getKey() == key)
                return Table[hash];
            Comparisons++;
        }
        ++hash;
        if (hash == TableSize - 1)
            hash = 0;
    }

    return NULL;
}


void HashTable::resize() {
    int oldSize = TableSize;
    TableSize *= 2;
    Cell** tmp = new Cell*[TableSize];
    for (int i = 0; i < TableSize; i++) 
        tmp[i] = nullptr;
    swap(Table, tmp);
    for (int i = 0; i < oldSize; i++) 
        if (tmp[i] != nullptr) {
            insert(tmp[i]->getValue());
            NumberOfElements--;
        }
    for (int i = 0; i < oldSize; i++)
        if (tmp[i] != nullptr) 
            delete tmp[i];
    delete[] tmp;
}


void HashTable::remove(string key)
{
    bool isDeleted = false;
    for (int i = 0; i < TableSize; i++)
    {
        int hash = PearsonHashing(key);
        if (Table[hash] != NULL && !Table[hash]->getDeleted()) {
            if (Table[hash]->getKey() == key)
            {
                delete Table[hash];
                this->Table[hash]->setDeleted(true);
                cout << "Deleted" << endl;
                isDeleted = true;
                break;
            }
        }
    }
    if (!isDeleted)
        cout << "Not found" << endl;
}