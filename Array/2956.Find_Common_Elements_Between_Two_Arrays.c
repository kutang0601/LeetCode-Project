#include <stdio.h>

//找到两个数组中的公共元素
//https://leetcode.cn/problems/find-common-elements-between-two-arrays/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findIntersectionValues(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) 
{
    int arr[100000] = {0};
    int x = 0;
    for (int a = 0; a < nums1Size; a++)
    {
        for (int b = 0; b < nums2Size; b++)
        {
            if (nums1[a] == nums2[b])
            {
                arr[x] = nums1[a];
                x++;
            }
        }
    }    

    int* ret = malloc(sizeof(int) * 2);
    int count1 = 0;
    int count2 = 0;
    for (int c = 0; c < nums1Size; c++)
    {
        for (int d = 0; d < x; d++)
        {
            if (arr[d] == nums1[c])
            {
                count1++;
                break;
            }
        }
    }

    for (int e = 0; e < nums2Size; e++)
    {
        for (int f = 0; f < x; f++)
        {
            if (arr[f] == nums2[e])
            {
                count2++;
                break;
            }
        }
    }
    
    ret[0] = count1;
    ret[1] = count2;

    *returnSize = 2;

    return ret;
}

//思路优化-降时间复杂度
int* findIntersectionValues(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *ret = malloc(sizeof(int) * 2);
    memset(ret, 0, sizeof(int) * 2);

    for (int i = 0; i < nums1Size; i++) 
    {
        for (int j = 0; j < nums2Size; j++) 
        {
            if (nums1[i] == nums2[j]) 
            {
                ret[0]++;
                break;
            }
        }
    }

    for (int i = 0; i < nums2Size; i++) 
    {
        for (int j = 0; j < nums1Size; j++) 
        {
            if (nums2[i] == nums1[j]) 
            {
                ret[1]++;
                break;
            }
        }
    }
    
    *returnSize = 2;
    return ret;
}
