#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
    int* ret = (int*)malloc(sizeof(int) * (digitsSize + 1));
    int next = 1;
    int lenth = 0;
    for (int n = digitsSize - 1; n >= 0; n--)
    {
        int new = digits[n] + next;
        if (new > 9)
        {
            next = new / 10;
        }
        else
        {
            next = 0;
        }
        digits[n] = new % 10;
        ret[lenth++] = digits[n];
    }   

    if (next != 0)
        ret[lenth++] = next;
    *returnSize = lenth;

    int right = lenth - 1;
    int left = 0;

    while(left <= right)
    {
        int temp = ret[left];
        ret[left] = ret[right];
        ret[right] = temp;
        left++;
        right--;
    }

    return ret;
}