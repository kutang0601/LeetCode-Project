#include <stdio.h>

//复杂度为o(nnm),简直是拉满了
//所以接下来降复杂度
int countValidSelections(int* nums, int numsSize) 
{

    int count1 = 0;
    int count2 = 0;
    int count = 0;
    for (int a = 0; a < numsSize; a++)
    {
        if (nums[a] == 0)
        {
            int arr[10000] = {0};
            for (int b = 0; b < numsSize; b++)
            {
                arr[b] = nums[b];
            }

            int x1 = a;
            int p1 = 0;
            while (x1 >= 0 && x1 <= numsSize - 1)
            {
                if (arr[x1] == 0)
                {
                    if (p1 == 0)
                        x1--;
                    else
                        x1++;
                }
                else
                {
                    arr[x1]--;
                    if (p1 == 0)
                    {
                        p1 = 1;
                        x1++;
                    }
                    else
                    {
                        p1 = 0;
                        x1--;
                    }
                }
            }

            for (int c = 0; c < numsSize; c++)
            {
                if (arr[c] == 0)
                {
                    count1++;
                }
            }
            if (count1 == numsSize)
            {
                count++;
            }

            for (int d = 0; d < numsSize; d++)
            {
                arr[d] = nums[d];
            }

            int x2 = a;
            int p2 = 0;
            while (x2 >= 0 && x2 <= numsSize - 1)
            {
                if (arr[x2] == 0)
                {
                    if (p2 == 0)
                        x2++;
                    else
                        x2--;
                }
                else
                {
                    arr[x2]--;
                    if (p2 == 0)
                    {
                        p2 = 1;
                        x2--;
                    }
                    else
                    {
                        p2 = 0;
                        x2++;
                    }
                }
            } 

            for (int e = 0; e < numsSize; e++)
            {
                if (arr[e] == 0)
                {
                    count2++;
                }
            }
            if (count2 == numsSize)
            {
                count++;
            }

            count1 = 0;
            count2 = 0;
        }
    }

    return count;
}

//使用前缀和来解决，复杂度将降为o(n)
int countValidSelections(int* nums, int numsSize) 
{
    int count = 0;

    int pre[100] = {0};
    int sum = 0;

    //存储前缀和
    for (int a = 0; a < numsSize; a++)
    {
        sum += nums[a];
        pre[a] = sum;
    }

    for (int b = 0; b < numsSize; b++)
    {
        int before = 0;
        int back = 0;

        if (nums[b] == 0)
        {
            before = pre[b];
            back = pre[numsSize - 1] - pre[b];

            //如果0前比0后大1，或者0后比0前大1，那么需要先从左或右加一刚刚好
            if (before - back == 1 || back - before == 1)
                count++;
            else if (before == back)//如果相等先向左或者向右都能成功
                count += 2;
        }
    }

    return count;
}