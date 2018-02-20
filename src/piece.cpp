#include "piece.h"
#include <stdlib.h>
// shape.c
struct Piece {
   PieceType* type;
   char buffer_start;
};

struct PieceType {
   int buffer_size;
   const char* (*name)(Piece*);
   int (*max_moves)(Piece*);
   void (*destroy)(Piece*);
};

PieceType* PieceType__create(
     int buffer_size,
     const char* (*name)(Piece*),
     int (*max_moves)(Piece*),
     void (*destroy)(Piece*)) {
   PieceType* result = (PieceType*) malloc(sizeof(PieceType));
   result->buffer_size = buffer_size;
   result->name = name;
   result->max_moves = max_moves;
   result->destroy = destroy;
   return result;
}

Piece* Piece__create(PieceType* type) {
  int size = sizeof(Piece) + type->buffer_size;
  Piece* result = (Piece*) malloc(size);
  result->type = type;
  return result;
}

PieceType* Piece__type(Piece* self) {
  return self->type;
}

void* Piece__buffer(Piece* self) {
   return (void*) &(self->buffer_start);
}

const char* Piece__name(Piece* self) {
  return self->type->name(self);
}

int Piece__max_moves(Piece* self) {
  return self->type->max_moves(self);
}

void Piece__destroy(Piece* p) {
   if (p) {
      p->type->destroy(p);
   }
}
