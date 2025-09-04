#include<stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

#define ty unsigned long long


int main(){
  ty var = 1ll <<63;
  std::cout << var<< '\n';
  std::cout << floor(log10(var));
  return 0;
}