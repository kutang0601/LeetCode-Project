#include <stdio.h>

bool hasAlternatingBits(int n) {
    int before = 0;
    int x = n;
    while (x)
    {
        if (x == n)
        {
            before = x % 2;
            x /= 2;
            continue;
        }
        int now = x % 2;
        if (now == before)
            return false;
        before = now;
        x /= 2;
    }
    return true;
    
}