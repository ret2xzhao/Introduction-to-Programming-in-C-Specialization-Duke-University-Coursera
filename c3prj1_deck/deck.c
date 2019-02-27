#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  }
// This should print out the contents of a hand. It should print each card (recall that you wrote print_card in Course 2), and a space after each card. Do not put a newline after the hand, as this function gets called to print a hand in the middle of a line of output.

int deck_contains(deck_t * d, card_t c) {
  return 0;
}
// This function should check if a deck contains a particular card or not.  If the deck does contain the card, this function should return 1.  Otherwise, it should return 0. (You will use this later to build the deck of remaining cards which are not in any player's hand).

void shuffle(deck_t * d){
}
// This function takes in a deck an shuffles it, randomly permuting the order of the cards. There are MANY valid ways to shuffle a deck of cards---we'll leave the specifics of the algorithm design up to you.  However, you will want to use random() to generate pseudo-random numbers.  (Pseudo-random numbers are quite sufficient here, since they are not used for security purposes).
// We will note that in trying to devise this algorithm, you should not try to shuffle a deck of cards "normally". Instead, you should take a small number of cards, and think about ways to shuffle them that involve using random numbers to swap their order, or pick positions for them, or similar principles.

void assert_full_deck(deck_t * d) {
}
// This function should check that the passed in deck contains ever valid card exactly once.  If the deck has any problems, this function should fail an assert.  This will be used to help you test your deck shuffling: we will shuffle a full deck, then call assert_full_deck, so that you can identfiy problems with the deck.  You can print any error messages you want if there is a problem. Hint: you already wrote deck_contains.

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
