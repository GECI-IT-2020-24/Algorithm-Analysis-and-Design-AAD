#ifndef dac
#define dac
#include <stdbool.h>
typedef struct {
  int min_val;
  int max_val;
} MinMax;

MinMax min_max(int *arr, int size);
bool is_equal(MinMax *a, MinMax *b);

#endif
