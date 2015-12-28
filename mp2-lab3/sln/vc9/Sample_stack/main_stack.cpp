#include "stack.h"
#include "stack.cpp"
#include <iostream>
using namespace std;

int main() {
  stack<int> TStack;
  TStack.push(0);
  TStack.push(1);
  TStack.push(3);
  TStack.push(7);
  TStack.push(-3);

  cout << "stack:" << endl;
  TStack.print();

  cout << "stack after pop" << endl;
  TStack.pop();
  TStack.print();

  cout << "push new elem 0" << endl;
  TStack.push(0);
  TStack.print();
  return 0;
}
