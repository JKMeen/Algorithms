#include "hash.h"

void main(){
	HashTable hashTable(113);
	int key;

	int size, number, money;
	string file, name;
	ifstream fin; // 파일 읽기를 위한 스트림 생성

	//cout << "<System> Input Data File >>> ";
	cout << "데이터 파일 ? ";
	cin >> file;

	fin.open(file);
	if (!fin)
		cout << "<System> File Open Err" << endl;

	// 파일 사이즈 읽기
	fin >> size;

	// 한사람의 정보
	for (int i = 0; i < size; i++){
		fin >> number;
		fin >> name;
		fin >> money;

		// 정보를 넣어줌
		hashTable.set(number, name, money);
	}

	fin.close(); // 파일 닫기

	while (true){
		cout << "검색할 순번은(1~300), 종료 -1 입력? ";
		//cout << "<System> Input Search Number(1~300), EXIT : -1 >>> ";
		cin >> key;
		if (key >= 1 && key <= 300){ // 키 검색
			hashTable.printKey(key);
		}
		else if (key == -1) { // 종료
			cout << "<System> Program exit" << endl;
			break;
		}
		else // 잘못된 키
			cout << "1과 300사이의 번호를 입력하세요." << endl;
		//cout << "<System> Input between 1 and 300 number" << endl;
	}
}