#include "hash.h"

void main(){
	HashTable hashTable(113);
	int key;

	int size, number, money;
	string file, name;
	ifstream fin; // ���� �б⸦ ���� ��Ʈ�� ����

	//cout << "<System> Input Data File >>> ";
	cout << "������ ���� ? ";
	cin >> file;

	fin.open(file);
	if (!fin)
		cout << "<System> File Open Err" << endl;

	// ���� ������ �б�
	fin >> size;

	// �ѻ���� ����
	for (int i = 0; i < size; i++){
		fin >> number;
		fin >> name;
		fin >> money;

		// ������ �־���
		hashTable.set(number, name, money);
	}

	fin.close(); // ���� �ݱ�

	while (true){
		cout << "�˻��� ������(1~300), ���� -1 �Է�? ";
		//cout << "<System> Input Search Number(1~300), EXIT : -1 >>> ";
		cin >> key;
		if (key >= 1 && key <= 300){ // Ű �˻�
			hashTable.printKey(key);
		}
		else if (key == -1) { // ����
			cout << "<System> Program exit" << endl;
			break;
		}
		else // �߸��� Ű
			cout << "1�� 300������ ��ȣ�� �Է��ϼ���." << endl;
		//cout << "<System> Input between 1 and 300 number" << endl;
	}
}