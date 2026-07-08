#include <stdlib.h>
#include <string.h>

#define MOD 1000000007LL

int* sumAndMultiply(char* s, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int n = strlen(s);

    // prefix sum of non-zero digits
    long long *prefSum = (long long*)calloc(n + 1, sizeof(long long));

    // positions and digits of non-zero characters
    int *pos = (int*)malloc(n * sizeof(int));
    int *digit = (int*)malloc(n * sizeof(int));

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        prefSum[i + 1] = prefSum[i];
        if (s[i] != '0') {
            prefSum[i + 1] += s[i] - '0';
            pos[cnt] = i;
            digit[cnt] = s[i] - '0';
            cnt++;
        }
    }

    // powers of 10
    long long *pow10 = (long long*)malloc((cnt + 1) * sizeof(long long));
    pow10[0] = 1;
    for (int i = 1; i <= cnt; i++)
        pow10[i] = (pow10[i - 1] * 10) % MOD;

    // prefix value of non-zero digits
    long long *prefVal = (long long*)calloc(cnt + 1, sizeof(long long));
    for (int i = 0; i < cnt; i++)
        prefVal[i + 1] = (prefVal[i] * 10 + digit[i]) % MOD;

    int *ans = (int*)malloc(sizeof(int) * queriesSize);

    for (int q = 0; q < queriesSize; q++) {
        int l = queries[q][0];
        int r = queries[q][1];

        long long sum = prefSum[r + 1] - prefSum[l];

        // lower_bound for first position >= l
        int lo = 0, hi = cnt;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (pos[mid] < l)
                lo = mid + 1;
            else
                hi = mid;
        }
        int left = lo;

        // upper_bound for last position <= r
        lo = 0;
        hi = cnt;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (pos[mid] <= r)
                lo = mid + 1;
            else
                hi = mid;
        }
        int right = lo - 1;

        if (left > right) {
            ans[q] = 0;
            continue;
        }

        int len = right - left + 1;

        long long x = (prefVal[right + 1] -
                      (prefVal[left] * pow10[len]) % MOD + MOD) % MOD;

        ans[q] = (int)((x * (sum % MOD)) % MOD);
    }

    free(prefSum);
    free(pos);
    free(digit);
    free(pow10);
    free(prefVal);

    *returnSize = queriesSize;
    return ans;
}