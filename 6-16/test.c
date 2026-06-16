#include <stdio.h>

/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int cmp(const void* a, const void* b) 
{
    return *(int*)a - *(int*)b;
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) 
{
    qsort(arr, arrSize, sizeof(int), cmp);
        
    *returnColumnSizes = (int*)malloc(arrSize * sizeof(int));
    for (int f = 0; f < arrSize; f++)
    {
        (*returnColumnSizes)[f] = 2;
    }

    int** arr1 = (int**)malloc(arrSize * sizeof(int*));
    for (int e = 0; e < arrSize; e++)
    {
        arr1[e] = (int*)malloc(2 * sizeof(int));
    }

    int count = 0;
    int min = -1;
    for (int c = 0; c < arrSize - 1; c++)
    {
        int temp1 = ((arr[c] - arr[c + 1]) > 0) ? arr[c] - arr[c + 1] : -(arr[c] - arr[c + 1]);
        if (min < 0)
        {
            min = temp1;
            arr1[count][0] = arr[c];
            arr1[count][1] = arr[c + 1];
            count++;
            continue;
        } 
        if (min > temp1)
        {
            min = temp1;
            count = 0;
            arr1[count][0] = arr[c];
            arr1[count][1] = arr[c + 1];
            count++;
        }
        else if (min == temp1)
        {
            arr1[count][0] = arr[c];
            arr1[count][1] = arr[c + 1];
            count++; 
        }
    }

    *returnSize = count;

    return arr1;
}
