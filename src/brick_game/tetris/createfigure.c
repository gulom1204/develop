#include "../../tetris.h"

TetFigure* createFigure() {
  TetFigure* figure = (TetFigure*)malloc(sizeof(TetFigure));
  figure->x = WIDTH / 2 - FIGURE_SIZE / 2;
  figure->y = 0;

  int shapes[7][FIGURE_SIZE][FIGURE_SIZE] = {
      {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},
      {{2, 2, 0, 0}, {0, 2, 2, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
      {{3, 3, 0, 0}, {3, 3, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
      {{4, 4, 4, 0}, {0, 4, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
      {{5, 5, 5, 0}, {5, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
      {{6, 6, 6, 0}, {0, 0, 6, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
      {{0, 7, 7, 0}, {7, 7, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}};
  int r1 = rand() % 7;
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      figure->shape[i][j] = shapes[r1][i][j];
    }
  }
  figure->color = r1 + 1;

  return figure;
}