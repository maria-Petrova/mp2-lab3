#include "list.h"
#include <iostream>
using namespace std;
template <class T>
list<T>::list() {
	pFirst = 0;
}

template <class T>
list<T>::list(list<T> &a) {
	pFirst = 0;
	node<T>* b = a.pFirst;
	while (b != 0) {
		insertL(b->val);
		b = b->next;
	}
}

template <class T>
list<T>::~list() {
	node<T> *b = pFirst;
	while (pFirst != 0) {
		pFirst = pFirst->next;
		delete b;
		b = pFirst;
	}
}

template <class T>
node<T>* list<T>::poisk(T _val) {
	if (pFirst == 0)
		throw std::exception("Empty list");

	node<T> *tmp = pFirst;
	while ((tmp != 0) && (tmp->val!= _val))
		tmp = tmp->next;
	if (tmp == 0)
		return 0;
	return tmp;
}

template <class T>
node<T>* list<T>::del(T _val)
{
	if (pFirst == 0)
		throw std::exception("Empty list");
	
	node<T> *tmp = pFirst;
	if (tmp->val == _val){
		pFirst = tmp->next;
		tmp->next = 0;
		return tmp;
	}
	while ((tmp->next != 0) && (tmp->next->val != _val))
		tmp = tmp->next;
	if (tmp->next == 0)
		return 0;
	node<T> *a = tmp->next;
	tmp->next = a->next;
	a->next = 0;
	return a;
}

template <class T>
void list<T>::print() {
	if (pFirst == 0) {
		cout << "Empty list" << endl;
		return;
	}

	node<T> *tmp = pFirst;
	while (tmp != 0) {
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

template <class T>
void list<T>::insertF(T _val) {
	node<T> *tmp = new node<T>();
	tmp->val = _val;
	tmp->next = pFirst;
	pFirst = tmp;
}

template <class T>
void list<T>::insertL(T _val) {
	node<T> *tmp = pFirst;
	if (pFirst == 0) {
		insertF(_val);
		return;
	}
	while (tmp->next != 0)
		tmp = tmp->next;
	node<T> *tmp1 = new node<T>();
	tmp1->val = _val;
	tmp1->next = 0;
	tmp->next = tmp1;
}

template <class T>
void list<T>::insertA(T _val, node<T> *a)
{
	if (pFirst == 0)
		throw std::exception("Empty list");
	node<T> *point = poisk(_val);
	if (point == 0)
		throw std::exception("Dont find");
	a->next = point->next;
	point->next = a;
}
template <class T>
node<T>* list<T>::GetFirst()
{
	return pFirst;
}