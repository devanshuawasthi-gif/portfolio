int uniqueXorTriplets(int* nums, int numsSize) {
    int m = 0;
    for (int i = 0; i < numsSize; i++) {
        m = fmax(m, nums[i]);
    }
    int u = 1;
    while (u <= m) {
        u <<= 1;
    }
    bool* one = (bool*)calloc(u, sizeof(bool));
    bool* two = (bool*)calloc(u, sizeof(bool));
    bool* three = (bool*)calloc(u, sizeof(bool));
    for (int i = 0; i < numsSize; i++) {
        int v = nums[i];
        one[v] = true;
        for (int x = 0; x < u; x++) {
            if (one[x]) {
                two[x ^ v] = true;
            }
        }
    }
    for (int i = 0; i < numsSize; i++) {
        int v = nums[i];
        for (int x = 0; x < u; x++) {
            if (two[x]) {
                three[x ^ v] = true;
            }
        }
    }
    int ans = 0;
    for (int x = 0; x < u; x++) {
        if (three[x]) {
            ans++;
        }
    }
    free(one);
    free(two);
    free(three);
    return ans;
}