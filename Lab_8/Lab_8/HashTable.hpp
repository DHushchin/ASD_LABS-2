#pragma once
#include <iostream>
#include <string>
#include <algorithm>    // std::shuffle
#include <chrono>       // std::chrono::system_clock
#include <random>       // std::default_random_engine
#include <vector>
using namespace std;

class Cell {
private:
	string key, value;
	bool isDeleted;
public:
	Cell();
	Cell(string key, string value);
	Cell(const Cell& other);
	void setKey(string value);
	void setValue(string key);
	void setDeleted(bool isDeleted);
	string getKey();
	string getValue();
	bool getDeleted();
};


class HashTable {
private:
	int TableSize, NumberOfElements, Comparisons;
	Cell** Table;
	string charset;
	unsigned int PearsonHashing(string x);
	void resize();
public:
	HashTable();
	HashTable(int size);
	string StringGenerator();
	int getSize();
	int getElements();
	int getComparisons();
	void insert(string value);
	void remove(string key);
	Cell* search(string key);
	void print();
};
