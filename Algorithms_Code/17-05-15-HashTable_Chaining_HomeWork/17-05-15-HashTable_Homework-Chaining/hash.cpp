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
	int addr = hash(key); //�ؽ� �� ���
	if (this->table[addr] == NULL) {
		cout << key << "�� �����ϴ�. " << endl;
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
	int addr = hash(key); //�ؽ� �� ���
	if (this->table[addr] == NULL)
		return NULL;

	if (this->table[addr]->key == key)
	{
		return this->table[addr];
	}
	else
	{
		Node* node = this->table[addr]->next;
		//�ڵ� �߰�
		while (node){ // node�� NULL�� �Ǹ� break
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
	cout << "\n## �ؽ� ���̺� ���� \n";
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
			cout << "������ ����" << endl;
		}
	}
}

void HashTable::printKey(int key)
{
	int addr = hash(key); //�ؽ� �� ���
	if (this->table[addr] == NULL)
		cout << "�ؽ����̺� �ȿ� ���� " << key << "�� �����ϴ�." << endl;
	else {
		if (this->table[addr]->key == key)
		{
			cout << "\n## �˻� ����" << endl;
			cout << "���� : " << table[addr]->key
				<< " �̸� : " << table[addr]->name
				<< " ������ : " << table[addr]->money
				<< endl << endl;
		}
		else
		{
			Node* node = this->table[addr]->next;
			while (node){ // node�� NULL�� �Ǹ� break
				if (node->key == key){
					cout << "\n## �˻� ����" << endl;
					cout << "���� : " << node->key
						<< " �̸� : " << node->name
						<< " ������ : " << node->money
						<< endl << endl;
					break;
				}
				if (node->next == NULL){
					cout << "�ؽ����̺� �ȿ� ���� " << key << "�� �����ϴ�." << endl;
					break;
				}
				else {
					node = node->next;
				}
			}
		}
	}
}
