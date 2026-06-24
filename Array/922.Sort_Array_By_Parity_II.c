#include <stdio.h>

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