#include "../../tetris.h"

void aftergameover(TetGame* game) {
  int startX = (SCREEN_WIDTH - WIDTH * 2) / 2;
  int startY = (SCREEN_HEIGHT - HEIGHT) / 2;

  // Очищаем экран
  clear();

  // Отображаем текущее состояние поля
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (game->field[i][j]) {
        attron(COLOR_PAIR(game->field[i][j]));
        mvprintw(startY + i, startX + j * 2, "[]");
        attroff(COLOR_PAIR(game->field[i][j]));
      } else {
        mvprintw(startY + i, startX + j * 2, "  ");
      }
    }
  }

  // Отображаем сообщение "Game Over" в новом окне
  WINDOW* gameOverWin =
      newwin(5, 20, startY + HEIGHT / 2 - 2, startX + WIDTH - 5);
  box(gameOverWin, 0, 0);
  mvwprintw(gameOverWin, 2, 5, "GAME OVER");
  wrefresh(gameOverWin);

  // Ожидаем нажатия клавиши
  getch();

  // Удаляем окно и очищаем память
  delwin(gameOverWin);
  freefield(game);
}
