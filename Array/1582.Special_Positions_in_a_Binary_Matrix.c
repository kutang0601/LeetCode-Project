#include <stdio.h>

int numSpecial(int** mat, int matSize, int* matColSize) 
{  
    int arr1[100] = {0};
    int arr2[100] = {0};

    int arr[10000][2] = {0};
    int n1 = 0;
    for (int n = 0; n < matSize; n++)
    {
        for (int m = 0; m < matColSize[n]; m++)
        {
            if (mat[n][m] == 1)
            {
                arr1[n]++;
                arr2[m]++;
                arr[n1][0] = n;
                arr[n1][1] = m;
                n1++;
            }
        }
    }
    
    int count = 0;
    
    for (int x = 0; x < n1; x++)
    {
        if (arr1[arr[x][0]] == 1 && arr2[arr[x][1]] == 1)
        {
            count++;
        }
    }

    return count;
}