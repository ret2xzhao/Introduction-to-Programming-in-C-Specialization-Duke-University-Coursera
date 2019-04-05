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

void count_win(deck_t ** hands, size_t n_hands, int * win_arr) {
  size_t largest_idx = 0;
  int compare_result = 0;
  int tie = 0;

  for (size_t j=1; j<n_hands; j++) {
    compare_result = compare_hands(hands[largest_idx],hands[j]);
    if (compare_result == -1) {
      largest_idx = j;
      tie = 0;
    }
    if (compare_result == 0) {
      tie = 1;
    }
  }
  if (tie) {
    win_arr[n_hands]++;
  } 
  else {
    win_arr[largest_idx]++;
  }
}

void free_ftr_cards(future_cards_t * fc) {
  for (size_t i=0; i<fc->n_decks; i++) {
    free((fc->decks[i]).cards);
  }
  free(fc->decks);
  free(fc);
}

void freeAll(future_cards_t * fc, deck_t ** hands, size_t n_hands, deck_t * remain_deck, int * win_arr){
  free_ftr_cards(fc);
  for(size_t i=0; i<n_hands; i++){
    free_deck(hands[i]);
  }
  free(hands);
  free_deck(remain_deck);
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
  size_t n_hands = 0;
  deck_t * remain_cards;
  int * win_arr = NULL;
  future_cards_t * fc = malloc(sizeof(*fc));
  fc->decks = NULL;
  fc->n_decks = 0;

  //Open the input file and read the hands in it (you just wrote read_input!)
  hands = read_input(f, &n_hands, fc);
  //Create a deck with the remaining cards (you just wrote build_remaining_deck)
  remain_cards = build_remaining_deck(hands, n_hands);

  //Create an array to count how many times each hand
  //wins, with one more element for if there was a tie
  //(so if there are 2 hands, you should have 3 elements).
  //and initialize all its values to 0.
  win_arr = realloc(win_arr, (n_hands+1)*sizeof(*win_arr));
  for (size_t k=0; k<n_hands+1; k++) {
    win_arr[k] = 0;
  }

  //Do each Monte Carlo trial (repeat num_trials times)
  for (int i=0; i<num_trials; i++) {
    //Shuffle the deck of remaining cards
    //(you wrote shuffle in Course 3)
    shuffle(remain_cards);
    //Assign unknown cards from the shuffled deck
    //(you just wrote future_cards_from_deck)
    future_cards_from_deck(remain_cards, fc);
    //Use compare_hands (from Course 3) to
    //figure out which hand won. Note that
    //with potentially more than 2 hands,
    //this is much like finding the max of
    //an array, but using compare_hands
    //instead of >.
    //Increment the win count for the winning
    //hand (or for the "ties" element of the array
    //if there was a tie).
    count_win(hands, n_hands, win_arr);
  }

  //After you do all your trials, you just need
  //to print your results, free any memory
  //you allocated, and close any open files.
  for (size_t h=0; h<n_hands; h++) {
    printf("Hand %zu won %u / %u times (%.2f%%)\n", h, win_arr[h], num_trials, 100*(float)win_arr[h]/(float)n_trails);
  }
  printf("And there were %u ties\n", win_arr[n_hands]);
  freeAll(fc, hands, n_hands, remain_cards, win_arr);
  
  if (fclose(f) !=0) {
    perror("fclose");
    fprintf(stderr, "Trying to close file.");
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}
