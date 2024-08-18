#include "../../tetris.h"

void printField(TetGame* game) {
  int startX = (SCREEN_WIDTH - WIDTH * 2) / 2;
  int startY = (SCREEN_HEIGHT - HEIGHT) / 2;

  clear();

  int scoreX = startX + WIDTH * 2 + 10;
  int scoreY = startY + HEIGHT / 2;
  mvprintw(scoreY, scoreX, "Score: %d", game->score);

  int levelY1 = scoreY + 2;
  mvprintw(levelY1, scoreX, "Level: %d", game->level);

  if (game->is_paused) {
    mvprintw(scoreY, scoreX, "     PAUSED --> P     ");
    mvprintw(scoreY + 2, scoreX, "      QUIT --> Q     ");
    refresh();
    return;
  }

  else {
    savelevel(game);
    int scoreY1 = startY + ((HEIGHT / 2) + 6);
    mvprintw(scoreY1, scoreX, "Score: %d", game->sc);
    int levelY2 = scoreY + 4;
    mvprintw(levelY2, scoreX, "Level: %d", game->lvl);
    drawBorders(startX, startY);
    for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
        if (game->field[i][j]) {
          attron(COLOR_PAIR(game->field[i][j]));
          mvprintw(startY + i + 1, startX + j * 2 + 1, "[]");
          attroff(COLOR_PAIR(game->field[i][j]));
          // game->fields->fields[i][j] = game->field[i][j];
        } else {
          mvprintw(startY + i + 1, startX + j * 2 + 1, "  ");
        }
      }
    }

    TetFigure* figure = game->figure;
    int color = getColorForFigure(figure);
    attron(COLOR_PAIR(color));

    for (int i = 0; i < FIGURE_SIZE; i++) {
      for (int j = 0; j < FIGURE_SIZE; j++) {
        if (figure->shape[i][j]) {
          mvprintw(startY + figure->y + i + 1, startX + (figure->x + j) * 2 + 1,
                   "[]");
        }
      }
    }
    attroff(COLOR_PAIR(color));
  }
  // Отображаем следующую фигуру
  printNextFigure(game->next_figure, startX, startY);

  refresh();
}