#include "stack.h"
#include "list.h"
#include "list.cpp"


template <class T>
stack<T>::stack() {
  List = new list<T>();
}

template <class T>
stack<T>::stack(stack<T> &a) {
  this->List = new list<T>(*(a.List));
}

template <class T>
stack<T>::~stack() {
  delete this->List;
}

template <class T>
int stack<T>::isEmpty() const {
  return (List->GetFirst() == 0);
}

template <class T>
int stack<T>::isFull() const {
  Node<T> *tmp;
  try {
    tmp = new Node<T>;
  }
  catch (...) {
    return 1;
  }
  delete tmp;
  return 0;
}

template <class T>
void stack<T>::push(T _val) {
  if (isFull())
    throw std::exception("Stack is full");
  List->insertF(_val);
}

template <class T>
T stack<T>::pop() {
  if (isEmpty())
    throw std::exception("Empty stack");
  T result = List->GetFirst()->key;
  Node<T> *f = List->del(result);
  delete f;
  return result;
}

template <class T>
bool stack<T>::operator == (const stack<T> &a) {
  if (List->GetFirst() == 0 && a.List->GetFirst() == 0)
    return true;
  if (List->GetFirst() == 0 || a.List->GetFirst() == 0)
    return false;
  Node<T> *f1 = List->GetFirst();
  Node<T> *f2 = a.List->GetFirst();
  while (f1->next != 0) {
    if (f1->key != f2->key)
      return false;
    f1 = f1->next;
    f2 = f2->next;
  }
  return true;
}

template <class T>
void stack<T>::print() {
  List->print();
}

template <class T>
T stack<T>::GetFirst() {
  if (isEmpty()) 
    throw std::exception("Empty stack");
  return List->GetFirst()->key;
}
