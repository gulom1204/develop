#include "../../tetris.h"

TetGame* createGame() {
  TetGame* game = (TetGame*)malloc(sizeof(TetGame));
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      game->field[i][j] = 0;
    }
  }
  game->figure = createFigure();
  game->next_figure = createFigure();
  game->status_game = 1;
  game->is_paused = 0;
  game->level = 1;
  game->score = 0;
  game->lvl = 0;
  return game;
}

void freeGame(TetGame* game) {
  if (game->figure) {
    free(game->figure);
  }
  if (game->next_figure) {
    free(game->next_figure);
  }
  if (game) {
    free(game);
  }
}