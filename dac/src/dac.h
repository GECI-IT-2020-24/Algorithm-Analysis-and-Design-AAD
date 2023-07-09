#ifndef dac
#define dac
#include <stdbool.h>
#include <stddef.h>

// Min Max -------------------------->
typedef struct {
  int min_val;
  int max_val;
} MinMax;

MinMax min_max(const int *arr, int size);
bool minmax_is_equal(const MinMax *a, const MinMax *b);

//---------------------------------->
// Quick Sort : )

// fn sig inspired by std lib  : )
// but implementation different aan, uses recursive approach and less optmised :
// ) why ? ans : kurachoode generic aan but applicable for all times, primitive
// array types inu ok aan. pakshe ivide int array kku matram pore ,then why?
// veruthe :
// )
//
// In : cmp fn (a,b)->int
// if  the returned integer is  >= 0 then the first value i.e a is taken
// else the 2nd value is taken i.e b
//
// int_cmp_asc can be used to sort 2 int array in ascending order : )

int int_cmp_asc(const void *, const void *);
// Warning : fn contains side effects . input array is modified
void quick_sort(void *arr, int arr_size, size_t elem_size,
                int cmp_fn(const void *, const void *));

// compare quick sort res with first param
// for unit test : )
bool cmp_sort_res(int *required, int *qsort_res, int size);
//---------------------------------->
#endif
