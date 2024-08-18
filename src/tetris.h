#ifndef TETRIS_H
#define TETRIS_H

// #include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_mixer.h>

#define FIGURE_SIZE 4
#define WIDTH 10
#define HEIGHT 20
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

typedef enum { ROTATE_CLOCKWISE, ROTATE_COUNTERCLOCKWISE } RotationDirection;

typedef struct {
  int fields[HEIGHT][WIDTH];
} TetField;

typedef struct {
  int color;
  int x, y;
  int shape[FIGURE_SIZE][FIGURE_SIZE];
} TetFigure;

typedef struct {
  int field[HEIGHT][WIDTH];
  TetFigure* figure;
  TetFigure* next_figure;  // Измените на указатель
  TetField* fields;
  int status_game;
  int is_paused;
  int level;
  int lvl;
  int sc;
  int score;
} TetGame;

// Forward declarations
void drawBorders(int startX, int startY);
void transpose(int matrix[FIGURE_SIZE][FIGURE_SIZE]);
void reverseRows(int matrix[FIGURE_SIZE][FIGURE_SIZE]);
void reverseColumns(int matrix[FIGURE_SIZE][FIGURE_SIZE]);
TetFigure* createFigure();
TetGame* createGame();
void updateLevel();
void freeGame(TetGame* game);
void dropNewFigure(TetGame* game);
void moveFigureLeft(TetGame* game);
void moveFigureRight(TetGame* game);
void moveFigureDown(TetGame* game);
void rotateFigureInDirection(TetFigure* figure, RotationDirection direction);
void rotateFigureInGame(TetGame* game, RotationDirection direction);
void initColors();
void printField(TetGame* game);
void runGame(TetGame* game);
int checkCollision(TetGame* game);
void mergeFigureToField(TetGame* game);
void clearLines(TetGame* game);
int getColorForFigure(TetFigure* figure);
void transposeOtherFigure(int matrix[FIGURE_SIZE][FIGURE_SIZE],
                          TetFigure* figure);
void printNextFigure(TetFigure* nextFigure, int startX, int startY);
TetField* createField();
void aftergameover(TetGame* game);
void freefield(TetGame* game);
void savelevel(TetGame* game);

#endif