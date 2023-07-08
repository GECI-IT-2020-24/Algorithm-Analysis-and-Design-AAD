#ifndef dac
#define dac
#include <stdbool.h>
#include <stddef.h>

// Min Max -------------------------->
typedef struct {
  int min_val;
  int max_val;
} MinMax;

MinMax min_max(int *arr, int size);
bool minmax_is_equal(MinMax *a, MinMax *b);

//---------------------------------->
// Sort Merge and Quick Sort : )

// fn sig inspired by std lib  : )
// but implementation different aan, uses recursive approach and less optmised :
// ) why ? ans : kurachoode generic aan. pakshe ivide int array kku matram pore
// ,then why? veruthe : )
//
// In : cmp fn (a,b)->int
// if  the returned integer is  >= 0 then the first value i.e a is taken
// else the 2nd value is taken i.e b
//
int int_cmp(void *, void *);
// Warning : fn contains side effects . input array is modified
void merge_sort(void *arr, size_t elem_count, size_t elem_size,
                int comp_fn(void *, void *));
// Warning : fn contains side effects . input array is modified
void quick_sort(void *arr, size_t arr_size, size_t elem_size,
                int comp_fn(void *, void *));

// compare both merge sort and quick sort res with first param
// for unit test : )
bool cmp_sort_res(int *required, int *qsort_res, int *msort_res,
                         int size);
//---------------------------------->
#endif
