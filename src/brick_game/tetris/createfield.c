#include "../../tetris.h"

TetField* createField() {
  TetField* new_field = (TetField*)malloc(sizeof(TetField));
  return new_field;
}
void freefield(TetGame* game) {
  if (game->fields->fields) {
    free(game->fields->fields);
  }
}