#pragma once
#include <iostream>

template <class T>
class node {
public:
	T val;
	node *next;
};

template <class T>
class list {
protected:
	node<T>* pFirst;
public:
	list();
	list(list &a);
	~list();

	node<T>* poisk(T _val);

	node<T>* del(T _val);

	void insertF(T _val);
	void insertL(T _val);
	void insertA(T _val, node<T>* a);
	
	void print();
	node<T>* GetFirst();
};
