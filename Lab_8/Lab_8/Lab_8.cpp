#include <iostream>
#include "HashTable.hpp"
using namespace std;

int main()
{
    HashTable hashtable;
    /*
    hashtable.insert("Dmytro");
    hashtable.insert("Hushchin");
    hashtable.insert("KPI");
    hashtable.insert("FICT");
    hashtable.insert("IP-02");
    hashtable.insert("ASD");
    */
    srand(time(NULL));
    for (int i = 0; i < 1000; i++)
        hashtable.insert(hashtable.StringGenerator());
    hashtable.print();
    
    Cell* tmp = hashtable.search("43");
    if (tmp != NULL)
        cout << tmp->getValue() << endl;
    else
        cout << "Not found" << endl;
    delete tmp;

    cout << "Number of elements: " << hashtable.getElements() << endl;
    cout << "Size: " << hashtable.getSize() << endl;
    cout << "Comparisons: " << hashtable.getComparisons() << endl;
    system("pause");
    return 0;
}