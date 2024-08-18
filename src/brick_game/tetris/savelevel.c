#include "../../tetris.h"

void savelevel(TetGame* game) {
  FILE* file = fopen("level.txt", "r");  // Открываем файл только для чтения

  if (file != NULL) {
    // Читаем сохраненные значения, если файл существует
    fscanf(file, "%d%d", &game->lvl, &game->sc);
    fclose(file);  // Закрываем файл после чтения

    // Открываем файл в режиме r+ для обновления
    file = fopen("level.txt", "r+");
  } else {
    // Если файл не существует, создаем его
    file = fopen("level.txt", "w");
  }

  if (file == NULL) {
    perror("Не удалось открыть файл");
    return;
  }

  // Если текущий уровень или счет больше сохраненного, обновляем файл
  if (game->level > game->lvl || game->score > game->sc) {
    rewind(file);  // Возвращаем указатель в начало файла
    fprintf(file, "%d\n%d", game->level, game->score);
  }

  fclose(file);  // Закрываем файл
}
