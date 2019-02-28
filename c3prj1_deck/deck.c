#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

//void print_hand(deck_t * hand) {
//  card_t ** ptr = hand->cards;
//  for (int i=0; i<(hand->n_cards); i++) {
//    print_card(**ptr);
//    printf("%s"," ");
//    ptr++;
//  }
//}

void print_hand(deck_t * hand) {
  for (int i=0; i<(hand->n_cards); i++) {
    print_card(*(hand->cards[i]));
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  card_t ** ptr = d->cards;
  for (int i=0; i<(d->n_cards); i++) {
    if(suit_letter(**ptr) == suit_letter(c) && value_letter(**ptr) == value_letter(c)) {
      return 1;
    }
    ptr++;
  }
  return 0;
}

void shuffle(deck_t * d) {
  card_t ** card = d->cards ;
  card_t * temp;
  size_t n =d->n_cards;
  int rand;
  for (int i=0; i<(n/2); i++) {
    rand = random()%n;
    temp = card[i];
    card[i] = card[rand];
    card[rand] = temp;
  }  
}

void assert_full_deck(deck_t * d) {
  for (int i=0; i<d->n_cards; i++)
    assert(deck_contains(d, card_from_num(i)));
}
