#include "list.h"
#include "list.cpp"
#include <iostream>
using namespace std;

int main() {
  list<int> nList;
  nList.insertL(7);
  nList.insertL(4);
  nList.insertL(9);
  nList.insertL(3);
  nList.insertL(2);
  
  cout << "My list :" << endl;
  nList.print();
 
  cout << "Copied list is equal :" << endl;
  list<int> nList1(nList);
  nList1.print();
  
  cout << "Insert element with key = 10 in the first position" << endl;
  nList1.insertF(10);
  nList1.print();
  
  cout << "Insert element with key = 10 in the last position" << endl;
  nList1.insertL(10);
  nList1.print();
 
  cout << "Insertion element with key = 10 after the element with key = 4" << endl;
  node<int> *a = new node<int>;
  a->val = 10;
  nList1.insertA(4, a);
 
  nList1.print();
  cout << "Delete element with key = 9" << endl;
  nList1.del(9);
  
  nList1.print();
  cout << "Erasing first element with key = 10" << endl;
  nList1.del(10);
  nList1.print();

  cout << "Get key from first element" << endl;
  cout << nList1.GetFirst()->val << endl;
  return 0;
}
