#include "arithmetic.h"
#include "stack.h"
#include "stack.cpp"
#include <map>
int prior(char a) {
  switch (a) {
    case '*': return 3;
    case '/': return 3;
    case '+': return 2;
    case '-': return 2;
    case '(': return 1;
    case '=': return 0;
    default: return -1;
  }
}

string arithmetic::arithmetic_notation(string str) {
  stack<char> operation;
  stack<char> operand;

  char curr;

  for (int i = 0; i < str.length(); i++) {
    curr = str[i];
    if (prior(curr) != -1) {
      if ((!operation.isEmpty()) && (prior(curr) <= prior(operation.GetFirst())) && (curr != '('))
        while ((!operation.isEmpty()) && (prior(curr) <= prior(operation.GetFirst())))
          operand.push(operation.pop());
      operation.push(curr);
      continue;
    }

    if (((curr >= 0x41) && (curr <= 0x5A)) || ((curr >= 0x61) && (curr <= 0x7A))) {
      operand.push(curr);
      continue;
    }

    if (curr == ')') {
      while ((!operation.isEmpty()) && (operation.GetFirst() != '('))
        operand.push(operation.pop());
      if (operation.isEmpty())
        throw std::exception("not found bracket");
      operation.pop();
      continue;
    }
    throw std::exception("invalid characters");
  }
    while (!operation.isEmpty()) {
      if (operation.GetFirst() == '(')
        throw std::exception("not found bracket");
      operand.push(operation.pop());
    }

    if (operand.isEmpty())
      throw std::exception("no data");

    string result;
    string cur;

    while (!operand.isEmpty()) {
      cur = operand.pop();
      result.insert(0, cur);
    }
    return result;
}

double arithmetic::arithmetic_calculation(string str) {
  if (str == "")
    throw std::exception("Empty expression");
  stack<double> operand;
	
  double leftOperand;
  double rightOperand;

  map<char, double> value;
  char curr;

  cout << "Input values: " << endl;
  for (int i = 0; i < str.length(); i++) {
    curr = str[i];
    if (((curr >= 0x41) && (curr <= 0x5A)) || ((curr >= 0x61) && (curr <= 0x7A))) {
      if (!value.count(curr)) {
        cout << " " << curr << " = ";
        cin >> value[curr];
        cout << endl;
      }
    operand.push(value[curr]);
    continue;
  }

    if (operand.isEmpty())
      throw std::exception("does not match the number of operands");
    rightOperand = operand.pop();
    if (operand.isEmpty())
		throw std::exception("does not match the number of operands");
    leftOperand = operand.pop();

    switch (curr) {
      case '+': {
        operand.push(leftOperand + rightOperand);
        break;
      }
      case '-':{operand.push(leftOperand - rightOperand); break; }
      case '*':{operand.push(leftOperand * rightOperand); break; }
      case '/':{operand.push(leftOperand / rightOperand); break; }
    }
  }

  double result = operand.pop();
  if (!operand.isEmpty())
    throw std::exception("many operands");
  return result;
}
