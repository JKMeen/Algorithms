#include "hash.h"
HashTable::HashTable(int size)
{
	this->tableSize = size;
	for (int i = 0; i < this->tableSize; i++)
		this->table[i] = NULL;
}

void HashTable::set(int key, string name, int money)
{
	Node *node = new Node;
	node->key = key;
	node->name = name;
	node->money = money;
	node->next = NULL;

	int addr = hash(key);

	if (this->table[addr] == NULL){
		this->table[addr] = node;
	}
	else {
		node->next = this->table[addr];
		this->table[addr] = node;
	}
}


void HashTable::del(int key)
{
	int addr = hash(key); //해시 값 계산
	if (this->table[addr] == NULL) {
		cout << key << "가 없습니다. " << endl;
		return;
	}

	Node* delNode = NULL;
	if (this->table[addr]->key == key) 	{
		delNode = this->table[addr];
		this->table[addr] = delNode->next;
	}
	else 	{
		Node* node = this->table[addr];
		Node* next = node->next;
		while (next){
			if (next->key == key){
				delNode = next;
				node->next = delNode->next;
				break;
			}
			else {
				node = next; // next == node->next
				next = next->next;
			}
		}
	}
	delete delNode;
}

Node* HashTable::get(int key)
{
	int addr = hash(key); //해시 값 계산
	if (this->table[addr] == NULL)
		return NULL;

	if (this->table[addr]->key == key)
	{
		return this->table[addr];
	}
	else
	{
		Node* node = this->table[addr]->next;
		//코드 추가
		while (node){ // node가 NULL이 되면 break
			if (node->key == key) return node;
			node = node->next;
		}
	}
	return  NULL;
}

int HashTable::hash(int key)
{
	return key%this->tableSize;
}

void HashTable::printAll()
{
	cout << "\n## 해시 테이블 내용 \n";
	for (int i = 0; i < this->tableSize; i++)	{
		cout << "(index:" << i << "): ";
		if (this->table[i] != NULL)		{
			Node* node = this->table[i];
			while (node->next)	{
				cout << node->key << "  ";
				node = node->next;
			}
			cout << node->key << endl;
		}
		else	{
			cout << "데이터 없음" << endl;
		}
	}
}

void HashTable::printKey(int key)
{
	int addr = hash(key); //해시 값 계산
	if (this->table[addr] == NULL)
		cout << "해시테이블 안에 순번 " << key << "가 없습니다." << endl;
	else {
		if (this->table[addr]->key == key)
		{
			cout << "\n## 검색 내용" << endl;
			cout << "순번 : " << table[addr]->key
				<< " 이름 : " << table[addr]->name
				<< " 적립금 : " << table[addr]->money
				<< endl << endl;
		}
		else
		{
			Node* node = this->table[addr]->next;
			while (node){ // node가 NULL이 되면 break
				if (node->key == key){
					cout << "\n## 검색 내용" << endl;
					cout << "순번 : " << node->key
						<< " 이름 : " << node->name
						<< " 적립금 : " << node->money
						<< endl << endl;
					break;
				}
				if (node->next == NULL){
					cout << "해시테이블 안에 순번 " << key << "가 없습니다." << endl;
					break;
				}
				else {
					node = node->next;
				}
			}
		}
	}
}
