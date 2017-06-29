#include "hash.h"

int main()
{ 
	HashTable hashTable(13);
	int key;

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		key = rand() % 100;
		hashTable.set(key);
	}
	hashTable.printAll();

	while (1) 	{
		cout << "������ key �� �Է�(���� -1�Է�): ";
		cin >> key;
		if (key != -1)
		{
			if (hashTable.get(key) != 0)  {
				hashTable.del(key);
				hashTable.printAll();
			}
			else cout << "�ؽ����̺� �ȿ� " << key << "�� �����ϴ�.\n";
		}
		else break;
	}
	cin.ignore();
	return 0;
}