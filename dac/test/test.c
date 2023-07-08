#include "../../unity/src/unity.h"
#include "../src/dac.h"

#define get_len(arr) (sizeof(arr) / sizeof(arr[0]))

void min_max_tests() {
  // case 1 -> 1 element
  int arr1[] = {3};
  MinMax res1 = min_max(arr1, get_len(arr1));
  MinMax req1 = (MinMax){3, 3};
  TEST_ASSERT_EQUAL(true, minmax_is_equal(&req1, &res1));

  // case 2 -> 2 elements
  int arr2[] = {8, 6};
  MinMax res2 = min_max(arr2, get_len(arr2));
  MinMax req2 = (MinMax){6, 8};
  TEST_ASSERT_EQUAL(true, minmax_is_equal(&req2, &res2));

  // case 3 -> multiple elements
  int arr3[] = {70, 10, 42, 818, 2, 100, 456, 45};
  MinMax res3 = min_max(arr3, get_len(arr3));
  MinMax req3 = (MinMax){2, 818};
  TEST_ASSERT_EQUAL(true, minmax_is_equal(&req3, &res3));
}

void sort_tests() {
  {
    // case 1 -> 1 element
    int arr1[] = {3};
    int *q_res1 = arr1;
    size_t arr1_len = get_len(arr1);
    size_t elem1_size = sizeof(arr1[0]);
    // allocate is stack : )
    // why no heap allocation
    // 1 element alle ulle : )
    int m_res1[get_len(arr1)];
    // calculate res
    quick_sort(q_res1, arr1_len, elem1_size, int_cmp);
    merge_sort(m_res1, arr1_len, elem1_size, int_cmp);
    int res1[] = {3};
    TEST_ASSERT_EQUAL(true, cmp_sort_res(res1, q_res1, m_res1, arr1_len));
  }
  {
    // case 2 -> multiple elements
    int arr2[] = {5, 20, 3, 55, 2, 1, 9, 40, 3};
    int *q_res2 = arr2;
    size_t arr2_len = get_len(arr2);
    size_t elem2_size = sizeof(arr2[0]);
    // allocate is stack : )
    int m_res2[get_len(arr2)];
    // calculate res
    // why no heap allocation
    // heap allocation -> overhead
    quick_sort(q_res2, arr2_len, elem2_size, int_cmp);
    merge_sort(m_res2, arr2_len, elem2_size, int_cmp);
    int res2[] = {1, 2, 3, 3, 5, 9, 20, 40, 55};
    TEST_ASSERT_EQUAL(true, cmp_sort_res(res2, q_res2, m_res2, arr2_len));
  }
  {
    // case 3 -> larger list with more duplicates : )
    int arr3[] = {500, 23,   3,    75, 75,  800, 94, 47,
                  2,   1002, 2001, 75, 890, 500, 65, 1628};
    int *q_res3 = arr3;
    size_t arr3_len = get_len(arr3);
    size_t elem3_size = sizeof(arr3[0]);
    // allocate is stack : )
    // why no heap allocation
    // heap allocation -> overhead
    int m_res3[get_len(arr3)];
    // calculate res
    quick_sort(q_res3, arr3_len, elem3_size, int_cmp);
    merge_sort(m_res3, arr3_len, elem3_size, int_cmp);
    int res3[] = {3,   23,  65,  75,   75, 75, 94,   500,
                  500, 800, 890, 1628, 47, 2,  1002, 2001};
    TEST_ASSERT_EQUAL(true, cmp_sort_res(res3, q_res3, m_res3, arr3_len));
  }
}

void setUp() {}

void tearDown() {}

int main() {
  UNITY_BEGIN();
  RUN_TEST(min_max_tests);
  return UNITY_END();
}
