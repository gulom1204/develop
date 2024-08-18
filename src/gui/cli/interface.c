#include <ncurses.h>

#include "../../tetris.h"

// void printInterface(TetGame* game, int linesCleared, int level) {
//     (void)game; // Простой способ "использовать" параметр, чтобы избежать
//     предупреждений

//     mvprintw(0, WIDTH * 2 + 5, "Tetris Game");
//     mvprintw(2, WIDTH * 2 + 5, "Level: %d", level);
//     mvprintw(3, WIDTH * 2 + 5, "Lines: %d", linesCleared);
//     mvprintw(5, WIDTH * 2 + 5, "Controls:");
//     mvprintw(6, WIDTH * 2 + 5, "Left:  Left Arrow");
//     mvprintw(7, WIDTH * 2 + 5, "Right: Right Arrow");
//     mvprintw(8, WIDTH * 2 + 5, "Rotate: Up Arrow");
//     mvprintw(9, WIDTH * 2 + 5, "Down:  Down Arrow");
//     mvprintw(10, WIDTH * 2 + 5, "Pause:  P");
//     mvprintw(11, WIDTH * 2 + 5, "Quit:   Q");
//     refresh();
// }
// Символ для отображения пикселя

void drawBorders(int startX, int startY) {
  // Верхняя граница
  mvhline(startY, startX, '-', WIDTH * 2 + 2);

  // Нижняя граница
  mvhline(startY + HEIGHT + 1, startX, '-', WIDTH * 2 + 2);

  // Левая граница
  mvvline(startY, startX, '|', HEIGHT + 2);

  // Правая граница
  mvvline(startY, startX + WIDTH * 2 + 1, '|', HEIGHT + 2);

  // Углы
  mvaddch(startY, startX, '+');
  mvaddch(startY, startX + WIDTH * 2 + 1, '+');
  mvaddch(startY + HEIGHT + 1, startX, '+');
  mvaddch(startY + HEIGHT + 1, startX + WIDTH * 2 + 1, '+');
}
void initColors() {
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
  init_pair(8, COLOR_GREEN, COLOR_BLACK);
}

int getColorForFigure(TetFigure* figure) { return figure->color; }
// int getColorForFigure(TetFigure* figure) {
//     // Возвращает цвет для каждой фигуры (просто пример)
//     switch (figure->shape[0][0]) { // Предположим, что цвет фигуры зависит от
//     первого элемента
//         case 1: return 1; // Красный для 1
//         case 2: return 2; // Зеленый для 2
//         case 3: return 3; // Синий для 3
//         case 4: return 4; // Синий для 3
//         case 5: return 5; // Синий для 3
//         case 6: return 6;
//         case 7: return 7; // Синий для 7
//         default: return 1; // Если не определен, используем красный
//     }
// }
