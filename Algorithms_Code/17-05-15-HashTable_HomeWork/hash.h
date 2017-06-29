#include <iostream>
#include <string>
#include <time.h>
#include <fstream>

#define DELETE -1
using namespace std;

class HashTable {
	int *table;
	string *name;
	int *money;
	int occupiedCount;
	int tableSize;

public:
	HashTable(int size = 13);
	~HashTable();
	void set(int key, string name, int money);
	int get(int key);
	void del(int key);
	int hash(int key);
	int hash2(int key);
	void reHash();
	void printAll();
	void printKey(int key);
};