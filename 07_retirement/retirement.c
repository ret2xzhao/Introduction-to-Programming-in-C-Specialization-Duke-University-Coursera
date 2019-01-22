#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void print_current_balance (int months, double balance) {
  printf("Age %3d month %2d you have $%.2lf\n", months/12, months%12, balance);
  return;
}

void retirement (int startAge, double initial, retire_info working, retire_info retired) {
  double balance = initial;
  int total_months = startAge;
  
  for (int i = 0; i < working.months; i++) {
    print_current_balance (total_months, balance);
    balance = balance + balance * working.rate_of_return;
    balance = balance + working.contribution;
    total_months = total_months + 1;
  }

  for (int j = 0; j < (retired.months+1); j++) {
    print_current_balance (total_months, balance);
    balance = balance + balance * retired.rate_of_return;
    balance = balance + retired.contribution;
    total_months = total_months + 1;
  }
}
  
int main(void) {
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045 / 12;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01 / 12;

  retirement (327, 21345, working, retired);
  return 0;
}
