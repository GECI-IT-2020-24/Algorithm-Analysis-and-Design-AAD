#include "../../unity/src/unity.h"
#include "../src/greedy.h"

#define get_len(arr) (sizeof(arr) / sizeof(arr[0]))

void frac_kp_tests(void) {
  KsItem items1[] = {{10, 3}, {8, 5}, {1, 2}};

  TEST_ASSERT_EQUAL(19, frac_knapsack(items1, get_len(items1), 20));

  KsItem items2[] = {{20, 12}, {110, 15}, {120, 12}, {23, 10}, {43, 20}};

  TEST_ASSERT_EQUAL(301, frac_knapsack(items2, get_len(items2), 60));
}

void setUp(void) {}

void tearDown(void) {}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(frac_kp_tests);
  return UNITY_END();
}
