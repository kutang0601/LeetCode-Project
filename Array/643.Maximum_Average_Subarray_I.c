#include <stdio.h>

//首先用遍历数组前numsSize - k个，然后同total数组的当前位置，加当前及后面k - 1个数之和
double findMaxAverage(int* nums, int numsSize, int k) {
    int total[100000] = {0};
    double arranges[100000] = {0.0};
    double max_arrange = 0.0;

    for (int i = 0; i <= numsSize - k; i++)
    {
        int a = k;
        while (a)
        {
            total[i] += nums[i + a - 1];
            a--;
        }

        arranges[i] = total[i] * 1.0 / k;

        if (i == 0)
        {
            max_arrange = arranges[i];
            continue;
        }

        if (max_arrange < arranges[i])
        {
            max_arrange = arranges[i];   
        }
    }

    return max_arrange;
}

//由于度杂度为o((n - k) * k)
//度杂度太高，采用滑动数组解题
double findMaxAverage(int* nums, int numsSize, int k) {
    int right = k - 1;
    int left = 0;
    int sums = 0;

    for (int i = left; i <= right; i++)
    {
        sums += nums[i];
    }

    int next = sums;
    while(right < numsSize - 1)
    {
        right++;
        next += nums[right];
        next -= nums[left]; 
        left++;
        if (next > sums)
        {
            sums = next;
        }
    }

    return sums * 1.0 / k;
} 