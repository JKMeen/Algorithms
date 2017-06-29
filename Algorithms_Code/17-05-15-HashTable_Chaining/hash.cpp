#include "hash.h"
HashTable::HashTable( )
{
	this->tableSize = TABLE_SIZE;
	for (int i = 0; i < this->tableSize; i++)
		this->table[i] = NULL;
}

void HashTable::set(int key)
{
	Node *node = new Node;
	node->key = key;
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

Node*  HashTable::get(int key)
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
		cout << "(index:" << i <<"): " ;
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

