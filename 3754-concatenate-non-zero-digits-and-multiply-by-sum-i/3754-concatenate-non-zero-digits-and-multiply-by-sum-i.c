long long sumAndMultiply(int n) {
    if (n == 0)
        return 0;

    int digits[20];
    int size = 0;

    while (n > 0) {
        digits[size++] = n % 10;
        n /= 10;
    }

    long long x = 0;
    int digitSum = 0;

    for (int i = size - 1; i >= 0; i--) {
        if (digits[i] != 0) {
            x = x * 10 + digits[i];
            digitSum += digits[i];
        }
    }

    return x * digitSum;
}