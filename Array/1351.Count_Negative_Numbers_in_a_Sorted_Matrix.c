#include <stdio.h>

//复杂度为O(m * n)
//从右向左，从上向下
int countNegatives(int** grid, int gridSize, int* gridColSize) 
{
    int count = 0;
    int row = 0;
    int list = gridColSize[0] - 1;

    while(row < gridSize && list >= 0)
    {
        if (grid[row][list] < 0)
        {
            count += gridSize - row;
            list--;
        }
        else
        {
            row++;
        }

    }

    return count;
}
