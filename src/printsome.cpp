#include <iostream>
using namespace std;

struct s {
  char a;
  char b;
};

static int a = 100;
s z{66,5};

int fn() {
  cout << "banch:" << z.a << endl;
  return 0;
}
