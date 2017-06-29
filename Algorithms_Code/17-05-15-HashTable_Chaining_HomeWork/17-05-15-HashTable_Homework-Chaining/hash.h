#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
using namespace std;

#define TABLE_SIZE 113

typedef struct node
{
	int key;
	string name;
	int money;

	struct node* next;
} Node;

class HashTable
{
	Node* table[TABLE_SIZE];
	int tableSize;

public:
	HashTable(int size = 113);
	void set(int key, string name, int money);
	Node* get(int key);
	void del(int key);
	int hash(int key);
	void printAll();
	void printKey(int key);
};
