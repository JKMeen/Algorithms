#include "hash.h"

HashTable::HashTable(int size)
{
	this->table = new int[size];
	this->name = new string[size];
	this->money = new int[size];

	// �������� �Ҵ���� �͵��� 0���� �ʱ�ȭ, �� ���� ����Ʈ ������ �����
	memset(this->table, 0, size*sizeof(int));
	//strset(this->name, "Nope", size*sizeof(string)); 
	memset(this->money, 0, size*sizeof(int)); 

	this->occupiedCount = 0;
	this->tableSize = size;
}

HashTable::~HashTable()
{
	delete this->table;
}

void HashTable::set(int key, string name, int money)
{
	int addr1, addr2;
	double usage;

	usage = this->occupiedCount / (double)this->tableSize;
	if (usage > 0.5) { // ������ 50% ������ ���ؽ�
		reHash();
	}

	addr1 = hash(key); //�ؽ��ּ� ���
	//cout << key << "��  �ּ�: " << addr1 << "  ";
	while (this->table[addr1] != 0 && this->table[addr1] != key) //�ٸ� Ű�� �̹� ����ִ� ���
	{
		addr2 = hash2(key); // �浹 �� �ٸ� �ּҿ� ����
		addr1 = (addr1 + addr2) % this->tableSize;
	}
	this->table[addr1] = key;
	this->name[addr1] = name;
	this->money[addr1] = money;
	this->occupiedCount++;
	//cout << "Ű�� �� �ּ�: " << addr1 << endl;
}

int HashTable::get(int key)
{
	int addr1 = hash(key);
	int addr2;

	while (this->table[addr1] != 0 && this->table[addr1] != key) //�ٸ� Ű�� �̹� ����ִ� ���
	{
		addr2 = hash2(key);
		addr1 = (addr1 + addr2) % this->tableSize;
	}
	return this->table[addr1];
}

void HashTable::del(int key)
{
	int addr1, addr2;

	addr1 = hash(key);
	if (this->table[addr1] == key) 	{
		this->table[addr1] = DELETE;
	}
	else 	{
		while (this->table[addr1] != 0 && this->table[addr1] != key) 		{
			addr2 = hash2(key);
			addr1 = (addr1 + addr2) % this->tableSize;
		}
		this->table[addr1] = DELETE;
	}
}

int HashTable::hash(int key)
{
	return key%this->tableSize;
}

int HashTable::hash2(int key)//�ι�° �ؽ� �Լ�
{
	return (key % 11 + 1);
}


void HashTable::reHash() // ���̺� ũ�Ⱑ ���� ��� ū ���̺�� �ű�
{
	int i = 0;
	int* oldTable = this->table;
	string* oldName = this->name;
	int* oldMoney = this->money;
	int oldSize = this->tableSize;

	// �� �ؽ� ���̺� �����
	int* newTable = new int[this->tableSize * 2];
	string* newName = new string[this->tableSize * 2];
	int* newMoney = new int[this->tableSize * 2];
	this->tableSize = this->tableSize * 2;

	memset(newTable, 0, sizeof(int)* this->tableSize);
	//strnset(newName, 0, sizeof(string)* this->tableSize);
	memset(newMoney, 0, sizeof(int)* this->tableSize);
	this->occupiedCount = 0;

	this->table = newTable;
	this->name = newName;
	this->money = newMoney;

	cout << "\n�ؽ� ���̺� ���� ���ο� ���̺� ũ�� : " << this->tableSize;
	for (i = 0; i < oldSize; i++) // ���� �ؽ� ���̺� �ִ� �����͸� �� �ؽ� ���̺�� �ű�
	{
		if (oldTable[i] != 0) 	{
			this->set(oldTable[i], oldName[i], oldMoney[i]);
		}
	}
	delete[] oldTable; // ���� �ؽ� ���̺� ����
}


void HashTable::printAll()
{
	cout << "## �ؽ� ���̺� ���� \n";
	for (int i = 0; i < this->tableSize; i++){
		if (this->table[i] == 0 || this->table[i] == DELETE)
			cout << "(index:" << i << "): " << "������ ����" << endl;
		else cout << "(index:" << i << "): " << this->table[i] << endl;

	}
}

void HashTable::printKey(int key)
{
	int addr1 = hash(key);
	int addr2;

	while (this->table[addr1] != 0 && this->table[addr1] != key) //�ٸ� Ű�� �̹� ����ִ� ���
	{
		addr2 = hash2(key);
		addr1 = (addr1 + addr2) % this->tableSize;
	}

	if (this->table[addr1] == 0 || this->table[addr1] == DELETE)
		cout << "�ؽ����̺� �ȿ� ���� " << key << "�� �����ϴ�." << endl;
		//cout << "Be Nonexistent '" << key << "' Data" << endl;
	else {
		cout << endl << "## �˻� ����" << endl;
		cout << "���� : " << this->table[addr1]
			<< " �̸� : " << this->name[addr1]
			<< " ������ : " << this->money[addr1] << "��"
			<< endl << endl;
		/*cout << "Number >>> " << this->table[addr1]
			<< ", Name >>> " << this->name[addr1]
			<< ", Money >>> " << this->money[addr1]
			<< endl;*/
	}
}