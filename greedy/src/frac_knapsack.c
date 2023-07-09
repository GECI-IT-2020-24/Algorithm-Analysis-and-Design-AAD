#include "../../dac/src/dac.h"
#include "greedy.h"

// Compare items
// b-a used bcos , we need to sort in desc order : )

int _cmp_item(const void *a, const void *b) {
  return ((KsItem *)b)->profit / ((KsItem *)b)->weight -
         ((KsItem *)a)->profit / ((KsItem *)a)->weight;
}

double frac_knapsack(KsItem *items, int item_count, double max_weight) {
  // use the quick_sort algo difined in oru dac header
  quick_sort((void *)items, item_count, sizeof(KsItem), _cmp_item);
  double res_profit = 0;
  double cur_weight = 0;
  // iterate over all items
  for (int i = 0; i < item_count; i++) {
    // check if the item weight is less than the current capacity ie remaining
    // space = max_weight - current weight
    // Note : for further optmization assign max_weight to weight and compare
    // with weight and decrement weight this results in less floating point
    // operations and faster performance.
    // Q.> why no optimization ?
    // ans.> just for better readablity : )
    if (items[i].weight <= (max_weight - cur_weight)) {
      // if yes , store the whole item
      res_profit += items[i].profit;
      // also incease the current weight
      cur_weight += items[i].weight;
    } else {
      // if unable to store the whole element , then a fraction of it is stored
      //  get fractional rofit by taking remaining_weight/current_item_weight *
      //  current_item_profit
      res_profit +=
          items[i].profit * (max_weight - cur_weight) / items[i].weight;
      break;
    }
  }
  return res_profit;
}
