#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) 
{
    if (intervalsSize == 1 || intervalsSize == 0)
    {
        return intervals;
    }    

    for (int m = 0; m < intervalsSize - 1; m++)
    {
        for (int n = 0; n < intervalsSize - m - 1; n++)
        {
            if (intervals[n][0] > intervals[n + 1][0])
            {
                int tmp1[2] = {intervals[n + 1][0], intervals[n + 1][1]};
                intervals[n + 1][0] = intervals[n][0];
                intervals[n + 1][1] = intervals[n][1];            
                intervals[n][0] = tmp1[0];
                intervals[n][1] = tmp1[1];
            }
        }
    }

    int ret_lenth = 0;
    int** ret = (int**)malloc(sizeof(int*) * 10000);
    for (int a = 0; a < 10000; a++)
    {
        ret[a] = (int*)malloc(sizeof(int) * 2);
    }

    *returnColumnSizes = (int*)malloc(sizeof(int) * 10000);
    for (int b = 0; b < 10000; b++)
    {
        (*returnColumnSizes)[b] = 2;
    }

    int len = 0;
    while(len < intervalsSize)
    {
        ret[ret_lenth][0] = intervals[len][0];


        int left = intervals[len][1];
        while (len + 1 < intervalsSize && left >= intervals[len + 1][0])
        {
            left = left > intervals[len + 1][1] ? left : intervals[len + 1][1];
            len++;
        }

        ret[ret_lenth][1] = left;

        len++;
        ret_lenth++;
    }

    *returnSize = ret_lenth;

    return ret;
}