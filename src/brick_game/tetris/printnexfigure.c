#include "../../tetris.h"

void printNextFigure(TetFigure* nextFigure, int startX, int startY) {
  int offsetX = 30;                 // Отступ по оси X
  int offsetY = 3;                  // Отступ по оси Y
  int width = FIGURE_SIZE * 3 + 2;  // Ширина рамки с учетом границ
  int height = FIGURE_SIZE + 3;  // Высота рамки с учетом границ

  // Отображаем текст "Next:"
  mvprintw(startY, startX + offsetX, "Next:");

  // Рисуем верхнюю границу
  mvprintw(startY + offsetY - 1, startX + offsetX - 1, "+");
  for (int i = 0; i < width - 2; i++) {
    mvprintw(startY + offsetY - 1, startX + offsetX + i, "-");
  }
  mvprintw(startY + offsetY - 1, startX + offsetX + width - 2, "+");

  // Рисуем нижнюю границу
  mvprintw(startY + offsetY + height - 2, startX + offsetX - 1, "+");
  for (int i = 0; i < width - 2; i++) {
    mvprintw(startY + offsetY + height - 2, startX + offsetX + i, "-");
  }
  mvprintw(startY + offsetY + height - 2, startX + offsetX + width - 2, "+");

  // Рисуем боковые границы
  for (int i = 0; i < height - 2; i++) {
    mvprintw(startY + offsetY + i, startX + offsetX - 1, "|");
    mvprintw(startY + offsetY + i, startX + offsetX + width - 2, "|");
  }

  // Отображаем фигуру внутри рамки
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      if (nextFigure->shape[i][j]) {
        attron(COLOR_PAIR(nextFigure->color));
        mvprintw(startY + offsetY + i, startX + 2 + offsetX + j * 2, "[]");
        attroff(COLOR_PAIR(nextFigure->color));
      }
    }
  }
}