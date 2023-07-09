#ifndef greedy
#define greedy
#include <stdbool.h>

typedef struct {
  double profit, weight;
} KsItem;

double frac_knapsack(KsItem *items, int item_size, double max_weight);

#endif
