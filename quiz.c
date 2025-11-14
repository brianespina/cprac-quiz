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
  question_t *question_list;
} game_t;

game_t *create_game() {
  game_t *new = malloc(sizeof *new);
  if (!new) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  question_t *question_list = malloc(sizeof *question_list);
  if (question_list) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  new->score = 0;
  new->dificulty = 1;
  new->question_list = question_list;

  return new;
}

void append_question(game_t *game, question_t question) {}

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
  add_question(g, "tiearnstina", "risntaioerste", 1);

  free(g);
  return EXIT_SUCCESS;
}
