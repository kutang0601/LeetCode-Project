#include <stdio.h>

int* numberOfLines(int* widths, int widthsSize, char* s, int* returnSize) {
    int row = 0;
    int total = 0;
    
    while (*s)
    {
        int down = (*s) - 'a';
        if (total % 100 < 100 && (total % 100) + widths[down] > 100)
        {
            total += (100 - (total % 100));
        }

        total += widths[down];
        s++;
    }

    int lastrow = 0;
    if (total % 100 > 0)
    {
        row = total / 100 + 1;
        lastrow = total % 100;
    }
    else
    {
        row = total / 100;
        lastrow = 100;
    }
    
    int* arr = malloc(sizeof(int) * 2);
    arr[0] = row;
    arr[1] = lastrow;
    *returnSize = 2;

    return arr;
}