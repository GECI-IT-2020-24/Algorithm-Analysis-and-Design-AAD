#include "dac.h"
// Quick sort function prototype
void _qsort(void *arr, size_t elem_size, int begin, int end,
            int cmp_fn(const void *, const void *));
int _partition(void *arr, size_t elem_size, int begin, int end,
               int cmp_fn(const void *, const void *));
// cast void pointer to int pointer and deref to get value
// then subtract
// if result is - ve then b is greater and b is chosen
int int_cmp_asc(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool cmp_sort_res(int *req, int *q_res, int size) {
  for (int i = 0; i < size; i++) {
    if (req[i] != q_res[i]) {
      return false;
    }
  }
  return true;
}

// now array swapping <stdlib def : ) >
// using temp
// why no XOR swap ?
// XOR swap great for integers
// pakshe pointers inte case il not safe : )
// this uses bytewise swap : )
// q.> why do {} while(0) ?
// ans : #define il varaibles define cheyyan pattila ,so wrap it in
// do{}while(0); now , this enables varaible definition.
// q.> why cast to char * ,
// bcos char is 1 byte , _swap swaps each byte till size reaches 0 , so itrate
// till size->0
// why create _size varaible ?
// else it will modify elem_size and after iteration elem_size becomes 0
#define _swap(a, b, elem_size)                                                 \
  do {                                                                         \
    size_t _size = elem_size;                                                  \
    char *_a = a, *_b = b;                                                     \
    while (_size--) {                                                          \
      char _temp = *_a;                                                        \
      *_a++ = *_b;                                                             \
      *_b++ = _temp;                                                           \
    }                                                                          \
  } while (0)

// get current position element pointer
// elem -> base_address of array + pos * number of bytes at each pos
//  [===ele1===][===ele2===][===ele3===][===ele4===]
//  ^<ele size eg: 6 bytes>
//  base addr of array 0xdeff0000
//  there for to get to addr of ele 3
//  we calc -> base address (0xdeff0000) + pos of ele i.e (3) *no of bytes for
//  each ele ie (6)
#define _elem(base_ptr, pos, elem_size) ((void *)(base_ptr + pos * elem_size))

void quick_sort(void *arr, int arr_size, size_t elem_size,
                int cmp_fn(const void *, const void *)) {
  _qsort(arr, elem_size, 0, arr_size - 1, cmp_fn);
}

void _qsort(void *arr, size_t elem_size, int begin, int end,
            int cmp_fn(const void *, const void *)) {
  if (begin < end) {
    // partition kazhinjal pivot in correct position
    // and after partition
    // <----element before pivot ---> p <----element after pivot---->
    //  ele before pivot -> will be lesser than or eq p
    //  like wise ele. after pivot -> greater than p
    int pivot = _partition(arr, elem_size, begin, end, cmp_fn);
    // then run quick sort on elements before pivot and on elements after pivot
    _qsort(arr, elem_size, begin, pivot - 1, cmp_fn);
    _qsort(arr, elem_size, pivot + 1, end, cmp_fn);
  }
}
int _partition(void *arr, size_t elem_size, int begin, int end,
               int cmp_fn(const void *, const void *)) {
  int i = begin + 1, j = end;
  // convert base address of arry to char pointer , oooro byte aayitt tranverse
  // cheyyan : )
  char *_arr_base = (char *)arr;
  // get pivot element -> pivot chosen as first element
  void *pivot = _elem(_arr_base, begin, elem_size);
  // therefore i=1+pivot
  // and j=end
  // <------------------->
  // p (i)->         <-(j)
  // now move i and j by
  //  increment i if i<=j and pivot >= arr[i]
  //  this moves i to the right till element > pivot is found
  //  next iteration where i<=j and pivot < arr[j]
  //  this moves j to the left till it reaches an element smaller than pivot
  //  then swap the elements at i and j
  //  base condition is met when i>j and function returns;
  // : )
  while (i <= j) {
    while (i <= j && (cmp_fn)(pivot, _elem(_arr_base, i, elem_size)) >= 0) {
      i++;
    }
    while (i <= j && (cmp_fn)(pivot, _elem(_arr_base, j, elem_size)) < 0) {
      j--;
    }
    if (i < j) {
      // swap the elements at i and j
      _swap(_elem(_arr_base, i, elem_size), _elem(_arr_base, j, elem_size),
            elem_size);
    }
  }
  // swap the pivot with j : )
  _swap(_elem(_arr_base, begin, elem_size), _elem(_arr_base, j, elem_size);
        , elem_size);
  // now j is the new pevot
  // return j
  return j;
}
