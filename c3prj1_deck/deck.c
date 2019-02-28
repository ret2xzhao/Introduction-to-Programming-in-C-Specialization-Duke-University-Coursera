#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  card_t ** ptr = hand->cards;
  for(int i=0; i<(hand->n_cards); i++){
    print_card(**ptr);
    printf("%s"," ");
    ptr++;
  }
}

int deck_contains(deck_t * d, card_t c) {
  card_t ** ptr = d->cards;
  for(int i=0; i<(d->n_cards); i++){
    if(suit_letter(**ptr)== suit_letter(c) && value_letter(**ptr)==value_letter(c)){
      return 1;
    }
    ptr++;
  }
  return 0;
}

void shuffle(deck_t * d){
  card_t ** card =d -> cards ;
  card_t * temp;
  size_t n=d ->n_cards;
  int rand;
  for (size_t i=0 ;i< n/2 ;i++){
    rand= rand()%n;
    temp=card[i];
    card[i]=card[rand];
    card[rand]=temp;
  }  
}

void assert_full_deck(deck_t * d) {
  card_t ** ptr = d->cards;
  deck_t temp_deck;
  temp_deck.cards = d->cards;
  for(int i=0; i<(d->n_cards); i++){
    card_t temp_card = **ptr;
    assert_card_valid(temp_card);
    if(i>0){
      temp_deck.n_cards = (size_t)i;
      assert(!deck_contains(&temp_deck, temp_card));
    }
    ptr++;
  }
}
