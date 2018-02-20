#include "rook.h"

struct Data {
   int x;
};

void Rook__destroy_override(Piece* p);

static auto count = 0;

static Data* Rook_data(Rook* r) {
   return (Data*) Piece__buffer((Piece*) r);
}

const char* Rook__name_override(Piece* self) {
   return "Rook";
}

int Rook_max_moves_override(Piece* self) {
   return 14;
}

static PieceType* rook_type =
       PieceType__create(
           sizeof(Data),
           &Rook__name_override,
           &Rook_max_moves_override,
           &Rook__destroy_override);

Rook* Rook__create(int x) {
  count++;
  Rook* result = (Rook*) Piece__create(rook_type);
  Data* data = Rook_data(result);
  data->x = x;
  return result;
}

void Rook__destroy_override(Piece* p) {
   free(p);
   count--;
   if (!count)
      free(rook_type);
}

void Rook__destroy(Rook* r) {
  Piece__destroy(Rook__to_Piece(r));
}

int Rook__x(Rook* r) {
  return Rook_data(r)->x;
}

Piece* Rook__to_Piece(Rook* square) {
   return ((Piece*) square);
}

Rook* Rook__from_Piece(Piece* piece) {
  if (!piece)  {
    return ((Rook*) 0);
  }

  PieceType* type = Piece__type(piece);
  if (type != rook_type) {
    return ((Rook*) 0);
  }
  return ((Rook*) piece);
}

template<typename Type> Type calculerSomme(Type operande1, Type operande2)
{
    Type resultat = operande1 + operande2;
    return resultat;
}

template double calculerSomme<double>(double operande1, double operande2);
