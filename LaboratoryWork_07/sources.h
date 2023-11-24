#pragma once
#include <iostream>
#include <string>

struct Employee {
	std::string full_name;
	std::string date_employment;

};

/*struct ListItem { // структура элемента односвязного списка(указатель только на следущий эллемент)
	int n; // значение элемента списка
	ListItem* pNext; // указатель на следущий элемент
};

struct MyList { // струкктура односвязного списка
	ListItem* pF = nullptr, * pE = nullptr; // указатели на первый и последний элементы односвязного списка
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