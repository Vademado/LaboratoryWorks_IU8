#pragma once
#include <iostream>
#include <string>

struct Employee {
	std::string full_name;
	std::string date_employment;

};

/*struct ListItem { // ��������� �������� ������������ ������(��������� ������ �� �������� ��������)
	int n; // �������� �������� ������
	ListItem* pNext; // ��������� �� �������� �������
};

struct MyList { // ���������� ������������ ������
	ListItem* pF = nullptr, * pE = nullptr; // ��������� �� ������ � ��������� �������� ������������ ������
};

*/

struct Node {
	int n;
	Node* pPrev;
	Node* pNext;
};

struct MyList {
	Node* pFirst = nullptr;
	Node* pEnd = nullptr;
};

void AddBegin(MyList& list, Node* p) {
	if (list.pFirst == nullptr) {

	}
}