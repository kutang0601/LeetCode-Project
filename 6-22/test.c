#include <stdio,h>

//交替位二进制数
//https://leetcode.cn/problems/binary-number-with-alternating-bits/
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

//按奇偶排序数组
//http://leetcode.cn/problems/sort-array-by-parity-ii/description/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    int* arr = malloc(sizeof(int) * numsSize);
    int n1 = 0;
    int n2 = 1;
    for (int a = 0; a < numsSize; a++)
    {
         if (nums[a] % 2 == 1)
         {
            arr[n2] = nums[a];
            n2 += 2;
         }
         else 
         {
            arr[n1] = nums[a];
            n1 += 2;
         }
    }

    *returnSize = numsSize;

    return arr; 
}

int main()
{

    return 0;
}