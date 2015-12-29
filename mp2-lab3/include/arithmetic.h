#pragma once

#include <iostream>
#include <string>
#include <map>
#include "stack.h"

using namespace std;
int size(string a);
class arithmetic {
  public:
    static string arithmetic_notation(string);
	static double calculation(string, map<char, double>);
};
