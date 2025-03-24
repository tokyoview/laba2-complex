#include <iostream>
#include "TComplex.h"

int main()
{
  TComplex<int> a;
  std::cin >> a;
  TComplex<double> b(1.0, 2.0);
  std::cout << b << std::endl;
  return 0;
}