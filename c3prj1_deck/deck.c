#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){

}

int deck_contains(deck_t * d, card_t c) {
  return 0;
}

void shuffle(deck_t * d){

}

void assert_full_deck(deck_t * d) {

}

#ifndef DECK_H
#define DECK_H
#include <stdlib.h>
#include "cards.h"
struct deck_tag {
  card_t ** cards;
  size_t n_cards;
};
typedef struct deck_tag deck_t;

void print_hand(deck_t * hand);
int deck_contains(deck_t * d, card_t c) ;
void shuffle(deck_t * d);
void assert_full_deck(deck_t * d) ;
//The below functions will be done in course 4.
deck_t * make_deck_exclude(deck_t * excluded_cards);
void add_card_to(deck_t * deck, card_t c);
card_t * add_empty_card(deck_t * deck);
void free_deck(deck_t * deck) ;
deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) ;
#endif
