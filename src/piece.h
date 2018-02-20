
struct Piece;
struct PieceType;

PieceType* PieceType__create(
   int buffer_size,
   const char* (*name)(Piece*),
   int (*max_moves)(Piece*),
   void (*destroy)(Piece*)
);

Piece* Piece__create(PieceType*);
PieceType* Piece__type(Piece*);
void* Piece__buffer(Piece*);

int Piece__max_moves(Piece*);
const char* Piece__name(Piece*);
void Piece__destroy(Piece*);
