#include "stack.h"
#include "stack.cpp"
#include <iostream>
using namespace std;

int main() {
  stack<int> nStack;
  cout << "Creation stack" << endl;
  nStack.push(4);
  nStack.push(6);
  nStack.push(3);
  nStack.push(8);
  nStack.push(9);
  nStack.push(11);

  cout << "My stack" << endl;
  nStack.print();

  cout << "My stack after pop" << endl;
  nStack.pop();
  nStack.print();

  cout << "Push new element 5 and top view" << endl;
  nStack.push(5);
  nStack.print();
  return 0;
}
