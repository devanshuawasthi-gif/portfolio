#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;

    if (x[0] == y[0])
        return y[1] - x[1]; 
    return x[0] - y[0]; 
}

int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort(intervals, intervalsSize, sizeof(int *), cmp);

    int count = 0;
    int maxEnd = 0;

    for (int i = 0; i < intervalsSize; i++) {
        if (intervals[i][1] > maxEnd) {
            count++;
            maxEnd = intervals[i][1];
        }
    }

    return count;
}