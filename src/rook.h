// rook.h
#include "piece.h"
#include <stdlib.h>
struct Rook;
Piece* Rook__to_Piece(Rook*);
Rook* Rook__from_Piece(Piece*);
Rook* Rook__create(int x);
int Rook__x(Rook*);

const char* Rook__name_override(Piece*);
int Rook_max_moves_override(Piece*);

void Rook__destroy(Rook*);

template<typename Type> Type calculerSomme(Type operande1, Type operande2);
