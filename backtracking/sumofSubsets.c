#include <stdio.h>

#define MAX_SIZE 100

void subsetSum(int set[], int n, int target, int subset[], int subsetSize, int sum, int start) {
    if (sum == target) {
        printf("Subset: ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }
    if (sum > target || start >= n) {
        return;
    }
    
    subset[subsetSize] = set[start];
    subsetSum(set, n, target, subset, subsetSize + 1, sum + set[start], start + 1);

    subsetSum(set, n, target, subset, subsetSize, sum, start + 1);
}

void findSubsetSum(int set[], int n, int target) {
    int subset[MAX_SIZE];
    subsetSum(set, n, target, subset, 0, 0, 0);
}

int main() {
    int set[] = {5, 10, 12, 13, 15, 18};
    int n = sizeof(set) / sizeof(set[0]);
    int target = 30;

    findSubsetSum(set, n, target);

    return 0;
}
