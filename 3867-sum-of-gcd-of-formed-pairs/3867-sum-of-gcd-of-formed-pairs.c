#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

long long gcdSum(int* nums, int numsSize) {
    int *prefixGcd = (int *)malloc(numsSize * sizeof(int));

    int mx = 0;

    // Build prefixGcd array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > mx)
            mx = nums[i];
        prefixGcd[i] = gcd(nums[i], mx);
    }

    // Sort the array
    qsort(prefixGcd, numsSize, sizeof(int), compare);

    // Pair smallest with largest
    long long ans = 0;
    int left = 0, right = numsSize - 1;

    while (left < right) {
        ans += gcd(prefixGcd[left], prefixGcd[right]);
        left++;
        right--;
    }

    free(prefixGcd);
    return ans;
}