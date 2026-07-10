#include <stdlib.h>
#include <string.h>

// Function to find GCD of two integers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2) {
    int n1 = strlen(str1);
    int n2 = strlen(str2);

    // Check if str1 + str2 == str2 + str1
    for (int i = 0; i < n1 + n2; i++) {
        char c1 = (i < n1) ? str1[i] : str2[i - n1];
        char c2 = (i < n2) ? str2[i] : str1[i - n2];

        if (c1 != c2) {
            char *ans = (char *)malloc(1);
            ans[0] = '\0';
            return ans;
        }
    }

    // Find GCD of lengths
    int len = gcd(n1, n2);

    // Create result string
    char *ans = (char *)malloc(len + 1);
    strncpy(ans, str1, len);
    ans[len] = '\0';

    return ans;
}