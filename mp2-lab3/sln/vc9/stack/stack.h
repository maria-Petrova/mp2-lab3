#pragma once

#include "list.h"

template <class T>
class stack {
  private:
    list<T>* List;
  public:
    stack();
    stack(stack<T> &a);
    ~stack();

    bool stack<T>::operator == (const stack<T>& a);
    int isFull() const;
    int isEmpty() const;
    void push(T _val);
    T pop();
    T GetFirst();
    void print();
};
