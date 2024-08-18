#include "../../tetris.h"

void moveFigureLeft(TetGame* game) {
  game->figure->x--;
  if (checkCollision(game)) {
    game->figure->x++;
  }
}

void moveFigureRight(TetGame* game) {
  game->figure->x++;
  if (checkCollision(game)) {
    game->figure->x--;
  }
}

void moveFigureDown(TetGame* game) {
  game->figure->y++;
  if (checkCollision(game)) {
    game->figure->y--;
    mergeFigureToField(game);
    clearLines(game);
    dropNewFigure(game);
  }
}