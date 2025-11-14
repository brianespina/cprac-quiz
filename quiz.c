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
  int question_count;
} game_t;

game_t *create_game() {
  game_t *new = malloc(sizeof *new);
  if (!new) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  new->score = 0;
  new->dificulty = 1;
  new->question_list = NULL;
  new->question_count = 0;
  return new;
}

void append_question(game_t *game, question_t q) {
  question_t *p = realloc(game->question_list,
                          sizeof(question_t) * (game->question_count + 1));
  if (!p) {
    perror("realloc");
    exit(EXIT_FAILURE);
  }
  game->question_list = p;
  *(game->question_list + game->question_count) = q;

  game->question_count++;
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
  add_question(g, "tiearnstina", "risntaioerste", 1);

  printf("%d\n", g->question_count);

  printf("%s\n", g->question_list[0].label);
  printf("%s\n", g->question_list[1].label);

  free(g);
  return EXIT_SUCCESS;
}
