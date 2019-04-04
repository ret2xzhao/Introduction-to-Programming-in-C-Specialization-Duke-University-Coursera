#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

void count_win(deck_t ** hands, size_t n_hands, int * win_arr){
  size_t bt_hd_idex = 0;
  int comp_res = 0;
  int tie_flag = 0;

  for(size_t j=1; j<n_hands; j++){
    comp_res = compare_hands(hands[bt_hd_idex],hands[j]);
    if(comp_res == -1){
      bt_hd_idex = j;
      tie_flag = 0;
    }
    if(comp_res == 0){
      tie_flag = 1;
    }
  }
  if(tie_flag){
    win_arr[n_hands]++;
  }else{
    win_arr[bt_hd_idex]++;
  }
}

void freeFutCards(future_cards_t * fc){
  for(size_t i=0; i<fc->n_decks; i++){
    free((fc->decks[i]).cards);
  }
  free(fc->decks);
  free(fc);
}

void freeAll(future_cards_t * fc, deck_t ** hands, size_t n_hands, deck_t * rem_deck, int * win_arr){
  freeFutCards(fc);
  for(size_t i=0; i<n_hands; i++){
    free_deck(hands[i]);
  }
  free(hands);
  free_deck(rem_deck);
  free(win_arr);
}

int main(int argc, char ** argv) {
  //Check command line arguments/report errors
  if (argc < 2) {
    fprintf(stderr, "Not enough arguments.\n");
    return EXIT_FAILURE;
  }
  if (argc > 3) {
    fprintf(stderr, "Too many arguments.\n");
    return EXIT_FAILURE;
  }

  FILE * f = fopen (argv[1], "r");
  if (f == NULL) {
    perror("fopen");
    fprintf(stderr, "Trying to open file.\n");
    return NULL;
  }
  int num_trials;
  if (argc == 2) {
    num_trials = 10000;
  }
  else {
    num_trials = atoi(argv[2]);
  }  
  deck_t ** hands;
  deck_t * rem_cards;
  size_t n_hands = 0;
  int * win_arr = NULL;

  future_cards_t * fc = (future_cards_t *)malloc(sizeof(*fc));
  fc->decks = NULL;
  fc->n_decks = 0;


  //Open the input file and read the hands in it (you just wrote read_input!)
  hands = read_input(f, &n_hands, fc);
  rem_cards = build_remaining_deck(hands, n_hands);
  win_arr = (int *)realloc(win_arr, (n_hands+1)*sizeof(*win_arr));
  for(size_t k=0; k<n_hands+1; k++){
    win_arr[k] = 0;
  }

  for(int i=0; i<num_trials; i++){
    shuffle(rem_cards);
    future_cards_from_deck(rem_cards, fc);
    count_win(hands, n_hands, win_arr);
  }
  for(size_t h=0; h<n_hands; h++){
    printf("Hand %zu won %u / %u times (%.2f%%)\n", h, win_arr[h], num_trials, 100*(float)win_arr[h]/(float)n_trails);
  }
  printf("And there were %u ties\n", win_arr[n_hands]);
  freeAll(fc, hands, n_hands, rem_cards, win_arr);
  
  if (fclose(f) !=0) {
    perror("fclose");
    fprintf(stderr, "Trying to close file.");
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}

//Open the input file and read the hands in it (you just wrote read_input!)
//Create a deck with the remaining cards (you just wrote build_remaining_deck)
//Create an array to count how many times each hand
//wins, with one more element for if there was a tie
//(so if there are 2 hands, you should have 3 elements).
//and initialize all its values to 0.
//Do each Monte Carlo trial (repeat num_trials times)
//Shuffle the deck of remaining cards
//(you wrote shuffle in Course 3)
//Assign unknown cards from the shuffled deck
//(you just wrote future_cards_from_deck)
//Use compare_hands (from Course 3) to
//figure out which hand won. Note that
//with potentially more than 2 hands,
//this is much like finding the max of
//an array, but using compare_hands
//instead of >.
//Increment the win count for the winning
//hand (or for the "ties" element of the array
//if there was a tie).
//After you do all your trials, you just need
//to print your results, free any memory
//you allocated, and close any open files.

  You should use the following format strings to report your results.
  For each hand, you should printf
  "Hand %zu won %u / %u times (%.2f%%)\n"
  where the %zu is the hand number (0,1,..)  [zu is for size_t]
  the first %u is the number of wins for that hand
  the second %u is the total number of trials
  the %.2f is the percentage that this win/trials ratio gives
  Then you should printf one more line for the ties:
  "And there were %u ties\n"
  Where the %u is just a count of how many ties there were
