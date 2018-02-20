#include "bishop.h"

struct Data {
   int x;
};
void Bishop__destroy_override(Piece* p);

static auto count = 0;

static Data* Bishop_data(Bishop* b) {
   return (Data*) Piece__buffer((Piece*) b);
}

const char* Bishop__name_override(Piece* self) {
   return "Bishop";
}

int Bishop_max_moves_override(Piece* self) {
   return 13;
}

static PieceType* bishop_type =
       PieceType__create(
           sizeof(Data),
           &Bishop__name_override,
           &Bishop_max_moves_override,
           &Bishop__destroy_override);

Bishop* Bishop__create(int x) {
  count++;
  Bishop* result = (Bishop*) Piece__create(bishop_type);
  Data* data = Bishop_data(result);
  data->x = x;
  return result;
}

void Bishop__destroy_override(Piece* p) {
   free(p);
   count--;
   if (!count)
      free(bishop_type);
}

void Bishop__destroy(Bishop* b) {
  Piece__destroy(Bishop__to_Piece(b));
}

int Bishop__x(Bishop* self) {
  return Bishop_data(self)->x;
}

Piece* Bishop__to_Piece(Bishop* p) {
   return ((Piece*) p);
}

Bishop* Bishop__from_Piece(Piece* piece) {
  if (!piece)  {
    return ((Bishop*) 0);
  }

  PieceType* type = Piece__type(piece);
  if (type != bishop_type) {
    return ((Bishop*) 0);
  }
  return ((Bishop*) piece);
}
