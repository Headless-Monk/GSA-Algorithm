#include <iostream>

#include "SetUpParams.h"

using std::cout;
using std::endl;

void testSetUpParam()
{
  SetUpParams params{};
  cout << params << endl;
  params.edit_params();
  cout << endl << params << endl;
}

int main()
{
  testSetUpParam();



  return 0;
}
