#include <stdlib.h>
#include <stdbool.h>

bool* pathExistenceQueries(int n,
                           int* nums,
                           int numsSize,
                           int maxDiff,
                           int** queries,
                           int queriesSize,
                           int* queriesColSize,
                           int* returnSize)
{
    int *component = (int *)malloc(numsSize * sizeof(int));

    int comp = 0;
    component[0] = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] - nums[i - 1] > maxDiff)
            comp++;
        component[i] = comp;
    }

    bool *ans = (bool *)malloc(sizeof(bool) * queriesSize);

    for (int i = 0; i < queriesSize; i++) {
        int u = queries[i][0];
        int v = queries[i][1];
        ans[i] = (component[u] == component[v]);
    }

    free(component);

    *returnSize = queriesSize;
    return ans;
}