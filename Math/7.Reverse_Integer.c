#include <stdio.h>


int reverse(int x) 
{
    int ans = 0;
    int judge = 1;
    if (x == INT_MIN)
        return 0;

    if (x < 0)
    {
        judge = 0;
        x *= -1;
    }

    while (x)
    {
        int dight = x % 10;
        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && dight > 7))
        {
            return 0;
        }
        ans = ans * 10 + dight;
        x /= 10;
    }
    
    return judge < 1 ? - ans : ans;
}