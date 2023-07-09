#include "dac.h"
#include <stdio.h>

// Compare both MinMax value
// unit testing inu aanu  : )
bool minmax_is_equal(const MinMax *a, const MinMax *b) {
  return a->max_val == b->max_val && a->min_val == b->min_val;
}

// Recursive function prototype
// ee fn aan nammude problethinte soln
// scope local , header il add cheythittilla : )
MinMax _get_min_max(const int *arr, int begin, int end);

// function invoked by unit tests : )
MinMax min_max(const int *arr, int size) {
  MinMax res = _get_min_max(arr, 0, size - 1);
  return res;
}

MinMax _get_min_max(const int *arr, int begin, int end) {
  // single element
  // 1 element matrame ullu engil min and max are same
  if (begin == end) {
    return (MinMax){arr[begin], arr[end]};
  }
  // 2 elements ie end-1 == begin
  // 2 element undenkil compare both and return MinMax
  // eg :  [7,3] , (begin=1 and end=2) , so , 2-1 == 1 then MinMax{3,7}
  else if (end - 1 == begin) {
    if (arr[end] > arr[begin]) {
      return (MinMax){arr[begin], arr[end]};
    } else {
      return (MinMax){arr[end], arr[begin]};
    }
  } else {
    // In case of mulitple elements
    // array 1/2 aaki divide cheyyukka : )
    // and find min and max of each half
    // divide until the above to cases (1 element / 2 elements) occur
    // a.k.a base cases. done by defining recursive function : ) .
    MinMax res = (MinMax){0, 0};
    int mid = (begin + end) / 2;
    // recursively divide as Left and right half
    /* eg :  [1,50,2,40,5]
     *
     *    call 1 :
     *     left arr -> [1,50], right arr -> [2,40,5]
     *    call 2-left:
     *      left reaches base case 2 i.e 2 elements : )
     *    call 2-right:
     *      right again divides
     *
     *    ...bakki swantham aayi cheyto : )
     */

    MinMax LMinMax = _get_min_max(arr, begin, mid);
    MinMax RMinMax = _get_min_max(arr, mid + 1, end);
    // Compare results from 2 halves and set the max value to result
    res.max_val =
        LMinMax.max_val > RMinMax.max_val ? LMinMax.max_val : RMinMax.max_val;
    // Compare results from 2 halves  and set the min value to result
    res.min_val =
        LMinMax.min_val < RMinMax.min_val ? LMinMax.min_val : RMinMax.min_val;
    return res;
  }
};
