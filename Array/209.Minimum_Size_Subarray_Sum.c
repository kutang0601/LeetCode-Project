#include <stdio.h>

//滑动数组思想
//如国加这个数字>=目标数时候就进入while循环储存长度并且减去左边的值
int minSubArrayLen(int target, int* nums, int numsSize){    
    int min_lenth = 0;
    int left = 0;
    int right = 0;
    int sums = 0;

    while (right < numsSize)
    {
        sums += nums[right];
        while (sums >= target)
        {   
            int lenth = right - left + 1;
            if (min_lenth == 0)
                min_lenth = lenth;
            else
                min_lenth = lenth > min_lenth ? min_lenth : lenth;
            sums -= nums[left];
            left++;
        }
        right++;
    }

    return min_lenth;
}