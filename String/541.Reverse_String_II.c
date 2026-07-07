#include <stdio.h>
#include <string.h>

// 反转字符串中 [l, r] 范围内的字符
void reverse(char* s, int l, int r) 
{
    while (l < r) {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
}

char* reverseStr(char* s, int k) {
    int n = strlen(s);
    for (int i = 0; i < n; i += 2 * k) 
    {
        int left = i;
        int right = (i + k - 1 < n) ? i + k - 1 : n - 1;
        reverse(s, left, right);
    }
    return s;
}