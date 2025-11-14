#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Question {
  char *label;
  char *answer;
  size_t dificulty;
} question_t;

typedef struct Game {
  size_t score;
  size_t dificulty;
  question_t question_list[5];
} game_t;

game_t *create_game() {
  game_t *new = malloc(sizeof *new);
  if (!new) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  new->score = 0;
  new->dificulty = 1;

  return new;
}

void append_question(game_t *game, question_t question) {
  long unsigned size = sizeof(game->question_list) / sizeof(question_t);
  question_t *list = game->question_list;
  int i = 0;
  while (list[i]) {
    i++;
  }
}

void add_question(game_t *game, char *label, char *answer, size_t dificulty) {
  question_t q;
  q.label = label;
  q.answer = answer;
  q.dificulty = dificulty;
  append_question(game, q);
}
int main(void) {
  game_t *g = create_game();
  add_question(g, "test", "test", 1);

  free(g);
  return EXIT_SUCCESS;
}
