#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >= 2 && c.value <= VALUE_ACE);
  assert(c.suit >= SPADES && c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r) {
  case STRAIGHT_FLUSH:
    printf("STRAIGHT_FLUSH");
    break;
  case FOUR_OF_A_KIND:
    printf("FOUR_OF_A_KIND");
    break;
  case FULL_HOUSE:
    printf("FULL_HOUSE");
    break;
  case FLUSH:
    printf("FLUSH");
    break;
  case STRAIGHT:
    printf("STRAIGHT");
    break;
  case THREE_OF_A_KIND:
    printf("THREE_OF_A_KIND");
    break;
  case TWO_PAIR:
    printf("TWO_PAIR");
    break;
  case PAIR:
    printf("PAIR");
    break;
  case NOTHING:
    printf("NOTHING");
    break;
  }
  return "";
}

char value_letter(card_t c) {
  switch(c.value) {
  case 2:
    return "2";
    break;
  case 3:
    return "3";
    break;
  case 4:
    return "4";
    break;
  case 5:
    return "5";
    break;
  case 6:
    return "6";
    break;
  case 7:
    return "7";
    break;
  case 8:
    return "8";
    break;
  case 9:
    return "9";
    break;
  case 10:
    return "0";
    break;
  case Jack:
    return "J";
    break;
  case Queen:
    return "Q";
    break;
  case King:
    return "K";
    break;
  case Ace:
    return "A";
    break;
  return 'x';
}


char suit_letter(card_t c) {
  if c.suit == "SPADES"; {
    printf("s");
  }
  else if c.suit == "HEARTS"; {
    printf("h");
  }
  else if c.suit == "DIAMONDS"; {
    printf("d");
  }
  else if c.suit == "CLUBS"; {
    printf("c");
  }
  return 'x';
}

void print_card(card_t c) {
  printf("%c" + "%c",value_letter(card_t c) ,suit_letter(card_t c))
    }

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let) {
  case "2": temp.value = "2";
    break;
  case "3": temp.value = "3";
    break;
  case "4": temp.value = "4";
    break;
  case "5": temp.value = "5";
    break;
  case "6": temp.value = "6";
    break;
  case "7": temp.value = "7";
    break;
  case "8": temp.value = "8";
    break;
  case "9": temp.value = "9";
    break;
  case "10": temp.value = "0";
    break;
  case "J": temp.value = VALUE_JACK;
    break;
  case "Q": temp.value = VALUE_QUEEN;
    break;
  case "K": temp.value = VALUE_KING;
    break;
  case "A": temp.value = VALUE_ACE;
    break;
  }
  switch(suit_let) {
  case "s": temp.value = SPADES;
    break;
  case "h": temp.value = HEARTS;
    break;
  case "d": temp.value = DIAMONDS;
    break;
  case "c": temp.value = CLUBS;
    break;
  }
  assert(assert_card_valid(temp));
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.suit = c / 13;
  temp.value = c % 13 + 2;
  return temp;
}
