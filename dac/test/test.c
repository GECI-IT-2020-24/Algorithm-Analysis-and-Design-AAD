#include "../../unity/src/unity.h"
#include "../src/dac.h"

#define get_len(arr) (sizeof(arr) / sizeof(arr[0]))

void min_max_tests() {
  // case 1 -> 1 element
  int arr1[] = {3};
  MinMax res1 = min_max(arr1, get_len(arr1));
  MinMax req1 = (MinMax){3, 3};
  TEST_ASSERT_EQUAL(true, is_equal(&req1, &res1));

  // case 2 -> 2 elements
  int arr2[] = {8, 6};
  MinMax res2 = min_max(arr2, get_len(arr2));
  MinMax req2 = (MinMax){6, 8};
  TEST_ASSERT_EQUAL(true, is_equal(&req2, &res2));

  // case 3 -> multiple elements
  int arr3[] = {70, 10, 42, 818, 2, 100, 456, 45};
  MinMax res3 = min_max(arr3, get_len(arr3));
  MinMax req3 = (MinMax){2, 818};
  TEST_ASSERT_EQUAL(true, is_equal(&req3, &res3));
}

void setUp() {}

void tearDown() {}

int main() {
  UNITY_BEGIN();
  RUN_TEST(min_max_tests);
  return UNITY_END();
}
