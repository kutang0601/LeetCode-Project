#include <stdio.h>

long long sumAndMultiply(int n) {
    long long x = 0;
    int p = 0;
    int sum = 0;
    while (n)
    {
        int k = n % 10;
        if (n % 10 != 0)
        {
            x += pow(10, p) * k;
            sum += k;
            p++;
        }
        n /= 10;
    }
    x *= sum;

    return x;
}