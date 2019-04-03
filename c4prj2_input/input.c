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
          i++;
          j++;
        }
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
  deck_t ** result = NULL;
  int n_hand = 0;
  char * line = NULL;
  size_t sz = 0;
  while(getline(&line, &sz, f)>=0) {
    result = realloc(result, (n_hand+1) * sizeof(*result));
    deck_t*deck=hand_from_string(line, fc);
    result[n_hand]=deck;
    n_hand ++;
  }
  free(line);
  *n_hands=n_hand;
  return result;
}
