#include <stdbool.h>
#include <stdlib.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize)
{
    *returnSize = candiesSize;

    bool* result = (bool*)malloc(sizeof(bool) * candiesSize);
    int maxCandies = candies[0];
    for (int i = 1; i < candiesSize; i++)
    {
        if (candies[i] > maxCandies)
            maxCandies = candies[i];
    }
    for (int i = 0; i < candiesSize; i++)
    {
        if (candies[i] + extraCandies >= maxCandies)
            result[i] = true;
        else
            result[i] = false;
    }

    return result;
}