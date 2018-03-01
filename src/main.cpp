
// new comment from github
// delete prec comment
#include "rook.h"
#include "bishop.h"
#include <iostream>
using namespace std;

Piece* list[2];

struct s {
  int a;
  int b;
};
//modif dans github
s z;
int fn();

int main() {
  list[0] = Rook__to_Piece(Rook__create(0));
  list[1] = Bishop__to_Piece(Bishop__create(2));

  for (int i = 0; i < 2; i++)  {
    cout << Piece__name(list[i]) << endl;
  }
  cout << Rook__x(Rook__from_Piece(list[0]))<< endl;
  //cout << Rook__name_override(Rook__to_Piece(rook)) << endl;

  for (int i = 0; i < 2; i++)  {
    Piece__destroy(list[i]);
  }
  // Rook__destroy(Rook__from_Piece(list[0]));
  // Bishop__destroy(Bishop__from_Piece(list[1]));

  int ** a;
  a = new int*[10];
  a[1] = new int[10];
  a[1][0] = 5;
  cout << "a[0][1] = " << a[1][0] << endl;
  z.a = 65;
  fn();
  int somme = calculerSomme(5.0, 6.0);
  cout << "somme: " << somme << endl;
  delete (a[1]);
  delete (a);
}
