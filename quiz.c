#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Question {
  char *label;
  size_t dificulty;
  char answer[100];
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

void add_question(game_t *game, char *label, char *answer, size_t dificulty) {
  question_t q;
  q.label = label;
  q.dificulty = dificulty;
  strcpy(q.answer, answer);

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

void free_game(game_t *game) {
  free(game->question_list);
  free(game);
}

void btolow(char *c) {
  if (*c >= 'A' && *c <= 'Z') {
    *c = *c + 32;
  }
}

char *stolow(char *s) {
  char *curr = s;
  while (*curr != '\0') {
    btolow(curr);
    curr++;
  }
  return s;
}

void strip_n(char *s) { s[strcspn(s, "\n")] = '\0'; }

int main(void) {
  game_t *g = create_game();
  add_question(g, "What gas do plants absorb from the air?", "CO2", 1);
  add_question(g, "What is the largest ocean on Earth?", "Pacific", 1);
  add_question(g, "What do bees make?", "Honey", 1);
  add_question(g, "What is the tallest animal?", "Giraffe", 1);
  add_question(g, "What friut keept the doctor away?", "Apple", 1);

  char buffer[100];

  for (int i = 0; i < g->question_count; i++) {
    printf("%s\n", g->question_list[i].label);
    fgets(buffer, sizeof(buffer), stdin);
    strip_n(buffer);
    stolow(buffer);

    char *ans = g->question_list[i].answer;
    stolow(ans);

    if (!strcmp(ans, buffer)) {
      g->score = g->score + 1;
    }
  }

  printf("score: %zu\n", g->score);

  free_game(g);

  return EXIT_SUCCESS;
}
