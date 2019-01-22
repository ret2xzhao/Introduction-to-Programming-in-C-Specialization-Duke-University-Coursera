#include <stdio.h>
#include <stdlib.h>

struct retire_info {
  int months;
  double contribution;
  double rate_of_return;
}
  typedef struct retire_info retire_info;

void print_current_balance (int months, double balance) {
  printf("Age %3d month %2d you have $%.2lf\n", month/12, month%12, balance);
}
  
balance = initial;
for (int i = 0; i < retire_info working.months; i++) {
  balance = balance + balance * retire_info working.rate_of_return;
  balance = balance + retire_info working.contribution;
  print_current_balance (int months, double balance);
 }

for (int j = 0; j < retire_info retired.months; j++) {
  balance = balance + balance * retire_info retired.rate_of_return;
  balance = balance + retire_info retired.spending;
  print_current_balance (int months, double balance);
 }

double balance () {
}

void retirement (int startAge, double initial, retire_info working, retire_info retired)

  int main(void) {
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045 / 12;

  retired.months = 384;
  retired.spending = -4000;
  retired.rate_of_return = 0.01 / 12;

  retirement (327, 21345, retire_info working, retire_info retired);
  return 0;
}
