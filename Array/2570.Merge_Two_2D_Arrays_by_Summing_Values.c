#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSize, int** nums2, int nums2Size, int* nums2ColSize, int* returnSize, int** returnColumnSizes) {
    int** ret = (int**)malloc(sizeof(int*) * (nums1Size + nums2Size));
    for (int a = 0; a < nums1Size + nums2Size; a++)
    {
        *(ret + a) = malloc(sizeof(int) * 2);
    }
    *returnColumnSizes = malloc(sizeof(int) * (nums1Size + nums2Size)) ;
    for (int b = 0; b < nums1Size + nums2Size; b++)
    {
        (*returnColumnSizes)[b] = 2;
    }

    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    while (n1 < nums1Size && n2 < nums2Size)
    {
        if (nums1[n1][0] > nums2[n2][0])
        {
            ret[n3][0] = nums2[n2][0];
            ret[n3][1] = nums2[n2][1];
            n3++;
            n2++;
        }
        else if (nums1[n1][0] < nums2[n2][0])
        {
            ret[n3][0] = nums1[n1][0];
            ret[n3][1] = nums1[n1][1];
            n3++;
            n1++;
        }
        else
        {
            ret[n3][0] = nums1[n1][0];
            ret[n3][1] = nums1[n1][1] + nums2[n2][1];
            n3++;
            n1++;
            n2++;
        }
    }

    while (n1 < nums1Size)
    {
        ret[n3][0] = nums1[n1][0];
            ret[n3][1] = nums1[n1][1];
            n3++;
            n1++;
    }
    while (n2 < nums2Size)
    {
        ret[n3][0] = nums2[n2][0];
            ret[n3][1] = nums2[n2][1];
            n3++;
            n2++;
    }


    *returnSize = n3;

    return ret;
}