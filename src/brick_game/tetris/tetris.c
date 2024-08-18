#include "../../tetris.h"

void transposeOtherFigure(int matrix[FIGURE_SIZE][FIGURE_SIZE],
                          TetFigure* figure) {
  int block[3][3];
  for (int i = 0; i < FIGURE_SIZE - 1; i++) {
    for (int j = 0, k = 2; j < FIGURE_SIZE - 1; j++, k--) {
      block[i][j] = matrix[k][i];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix[i][j] = block[i][j];
    }
  }
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      if (matrix[i][j]) {
        int new_x = figure->x + j + 1;
        if (new_x == WIDTH) {
          new_x -= 1;
        } else {
          new_x += 1;
        }
      }
    }
  }
}

int checkFigure(int matrix[FIGURE_SIZE][FIGURE_SIZE]) {
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      if (matrix[i][j] == 1) {
        return 1;
      }
    }
  }
  return 0;
}

void transpose(int matrix[FIGURE_SIZE][FIGURE_SIZE]) {
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = i + 1; j < FIGURE_SIZE; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
}

void reverseRows(int matrix[FIGURE_SIZE][FIGURE_SIZE]) {
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE / 2; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[i][FIGURE_SIZE - 1 - j];
      matrix[i][FIGURE_SIZE - 1 - j] = temp;
    }
  }
}

void reverseColumns(int matrix[FIGURE_SIZE][FIGURE_SIZE]) {
  for (int i = 0; i < FIGURE_SIZE / 2; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[FIGURE_SIZE - 1 - i][j];
      matrix[FIGURE_SIZE - 1 - i][j] = temp;
    }
  }
}
void dropNewFigure(TetGame* game) {
  if (game->figure) {
    free(game->figure);
  }
  game->figure = game->next_figure;
  game->next_figure = createFigure();
  if (checkCollision(game)) {
    game->status_game = 0;
  }
}
void rotateFigureInDirection(TetFigure* figure, RotationDirection direction) {
  if (checkFigure(figure->shape)) {
    transpose(figure->shape);
    if (direction == ROTATE_CLOCKWISE) {
      reverseRows(figure->shape);
    } else {
      reverseColumns(figure->shape);
    }
  } else {
    transposeOtherFigure(figure->shape, figure);
  }
}

void rotateFigureInGame(TetGame* game, RotationDirection direction) {
  TetFigure temp = *game->figure;

  rotateFigureInDirection(game->figure, direction);

  if (checkCollision(game)) {
    *game->figure = temp;
  }
}
int checkCollision(TetGame* game) {
  TetFigure* figure = game->figure;
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      if (figure->shape[i][j]) {
        int newX = figure->x + j;
        int newY = figure->y + i;
        if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= HEIGHT ||
            game->field[newY][newX]) {
          return 1;
        }
      }
    }
  }
  return 0;
}

void mergeFigureToField(TetGame* game) {
  TetFigure* figure = game->figure;
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      if (figure->shape[i][j]) {
        game->field[figure->y + i][figure->x + j] = figure->color;
      }
    }
  }
}
// void levelscore(TetGame* game) {
//     FILE *file = fopen("level.txt", "r");
//     if (file == NULL) {
//         perror("Can't open the file");
//     }

// }
void clearLines(TetGame* game) {
  int linesCleared = 0;
  for (int i = 0; i < HEIGHT; i++) {
    int filled = 1;
    for (int j = 0; j < WIDTH; j++) {
      if (!game->field[i][j]) {
        filled = 0;
        break;
      }
    }
    if (filled) {
      linesCleared++;
      for (int k = i; k > 0; k--) {
        for (int j = 0; j < WIDTH; j++) {
          game->field[k][j] = game->field[k - 1][j];
        }
      }
      for (int j = 0; j < WIDTH; j++) {
        game->field[0][j] = 0;
      }
    }
  }
  if (linesCleared == 1) {
    game->score += linesCleared * 100;
  } else if (linesCleared == 2) {
    game->score += (linesCleared + 1) * 100;
  } else if (linesCleared == 3) {
    game->score += (linesCleared + 4) * 100;
  } else if (linesCleared == 4) {
    game->score += (linesCleared + 11) * 100;
  }

  if (game->score >= 600) {
    game->level = game->score / 600 + 1;
  }
}
void updateLevel(TetGame* game) {
  int linesCleared = game->score / 600;
  game->level = linesCleared + 1;
}

void runGame(TetGame* game) {
  int ch = getch();
  int speed = 10;
  if (game->level > 1) {
    halfdelay(speed);
    speed -= 1;
  } else {
    halfdelay(speed);
  }
  switch (ch) {
    case KEY_LEFT:
      moveFigureLeft(game);
      break;
    case KEY_RIGHT:
      moveFigureRight(game);
      break;
    case ERR:
      moveFigureDown(game);
      break;
    case KEY_DOWN:
      moveFigureDown(game);
      break;
    case KEY_UP:
      rotateFigureInGame(game, ROTATE_CLOCKWISE);
      break;
    // case ' ':
    //     while (!checkCollision(game)) {
    //         moveFigureDown(game);
    //     }
    //     break;
    case 'p':
      game->is_paused = !game->is_paused;
      break;
    case 'q':
      game->status_game = !game->status_game;
      // aftergameover(game);
      break;
      // case 'w':
      //     rotateFigureInGame(game, ROTATE_CLOCKWISE);
      //     break;
      // case 'e':
      //     rotateFigureInGame(game, ROTATE_COUNTERCLOCKWISE);
      //     break;
      // default:
      //     break;
  }

  printField(game);
}
int main() {
  srand(time(NULL));
  TetGame* game = createGame();

  initscr();
  cbreak();
  curs_set(0);
  noecho();
  keypad(stdscr, TRUE);

  if (has_colors()) {
    initColors();
  }

  int dropDelay = 500;  // Задержка в миллисекундах
  int lastDropTime = 0;

  while (game->status_game) {
    runGame(game);

    struct timeval tv;
    gettimeofday(&tv, NULL);
    int currentTime = tv.tv_sec * 100 + tv.tv_usec / 100;

    if (!game->is_paused && (currentTime - lastDropTime >= dropDelay)) {
      moveFigureDown(game);
      lastDropTime = currentTime;
    }

    dropDelay = 500 - (game->level - 1) * 50;
    if (dropDelay < 100) dropDelay = 100;
  }
  // aftergameover(game);
  savelevel(game);
  endwin();
  freeGame(game);
  return 0;
}
