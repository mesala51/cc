
#include "piece.h"
#include <stdlib.h>
struct Bishop;
Piece* Bishop__to_Piece(Bishop*);
Bishop* Bishop__from_Piece(Piece*);
Bishop* Bishop__create(int x);
int Bishop__x(Bishop* self);

const char* Bishop__name_override(Piece*);
int Bishop_max_moves_override(Piece*);

void Bishop__destroy(Bishop*);
