#include "list.h"
#include "list.cpp"
#include <iostream>
using namespace std;

int main() {
  list<int> TList;
  TList.insertL(0);
  TList.insertL(8);
  TList.insertL(3);
  TList.insertL(-3);
  
  cout << "list:" << endl;
  TList.print();
 
  cout << "copied list:" << endl;
  list<int> TList1(TList);
  TList1.print();
  
  cout << "insert elem 22" << endl;
  TList1.insertF(22);
  TList1.print();
  
  cout << "insert elem 22 in the last position" << endl;
  TList1.insertL(22);
  TList1.print();
 
  cout << "inser elem 22 after the element with key = 8" << endl;
  node<int> *a = new node<int>;
  a->val = 22;
  TList1.insertA(8, a);
 
  TList1.print();
  cout << "Delete element with key = 9" << endl;
  TList1.del(9);
  
  TList1.print();
  cout << "Erasing first element with key = 10" << endl;
  TList1.del(10);
  TList1.print();

  cout << "Get key from first element" << endl;
  cout << TList1.GetFirst()->val << endl;
  return 0;
}
