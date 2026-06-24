#include <stdio.h>

//最少翻转次数得到反转二进制字符串
//https://leetcode.cn/problems/minimum-number-of-flips-to-reverse-binary-string/description/
int minimumFlips(int n) {
    int x = n;
    char ch[10000] = {0};
    int count = 0;

    while(x)
    {
        ch[count] = x % 2;
        x /= 2;
        count++;
    }

    char ch1[10000] = {0};
    int count1 = count - 1;
    for (int a = 0; a < count; a++)
    {
        ch1[a] = ch[count1];
        count1--;
    }

    int ret = 0;
    for (int b = 0; b < count; b++)
    {
        if (ch[b] != ch1[b])
        {
            ret++;
        }
    }

    return ret;
}



int main()
{
    
    return 0
}