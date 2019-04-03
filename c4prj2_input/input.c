#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
#include "cards.h"
#include "future.h"

deck_t * hand_from_string(const char * str, future_cards_t * fc) {
  deck_t * deck = malloc(sizeof(*deck));
  deck->cards = NULL;
  deck->n_cards = 0;
  for(int i=0; i<strlen(str); i++) {
    if ((str[i] == ' ') || (str[i] == '\n')) {
      continue;
    }
    else {
      if(str[i] == '?') {
        i++;
        int j=0;
        char index[2];
        while (!((str[i] == ' ') || (str[i] == '\n'))) {
          index[j] = str[i];
        }
        i++;
        j++;
        index[j] = '\0';
        add_future_card(fc, atoi(index), add_empty_card(deck));
      }
      else {
        add_card_to(deck, card_from_letters(str[i], str[i+1]));
        i++;
      }
    }
    if(deck->n_cards < 5) {
      fprintf(stderr, "Not enough cards.");
      return NULL;
    }
  }
  return deck;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc) {
  FILE * input = fopen (f, "r");
  if (input == NULL) {
    perror("fopen");
    fprintf(stderr, "Trying to open %s\n", f);
    return NULL;
  }
  
  deck_t ** result = malloc(sizeof(**result));
  result->cards = NULL;
  result->n_cards = 0;
  char * line = NULL;
  size_t sz = 0;
  int counter = 0;
  while(getline(&line, &sz, input)>0) {
    deck_t ** result = realloc(deck_t ** result, (result->n_cards+1) * sizeof(*deck_t ** result));
    hand_from_string(line, fc);
    free(line);
    line = NULL;
    n_cards++;
  }
  free(line);
  n_hands = n_cards;

  if (fclose(input) !=0) {
    perror("fclose");
    fprintf(stderr, "Trying to close %s\n", f);
    return NULL;
  }
  return result;
}
