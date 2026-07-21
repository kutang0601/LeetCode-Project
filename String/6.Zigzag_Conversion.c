#include <stdio.h>

char* convert(char* s, int numRows) {
    if (numRows == 1 || *s == 0)
        return s;

    char* ret = malloc(sizeof(char) * 10000);
    char ch[1000][1000] = {0};

    int list = 0;
    int row = 0;
    int list_max = 0;
    int row_max = 0;

    int numrow = numRows - 1;
    int numlist = numRows - 1;
    while (*s)
    {
        if (list == 0 || list % numlist == 0)
        {
            while (*s && row <= numrow)
            {
                ch[row][list] = *s; 
                s++;
                row++;
            }
            row--;
            row_max = row > row_max ? row : row_max;
            if (*s != 0)
            {
                row--;
                list++;
            }
        }   
        else
        {
            ch[row][list] = *s;
            row--;
            list++;
            s++;
        }
        list_max = list;
    }

    int x = 0;
    for (int n = 0; n <= row_max; n++)
    {
        for (int m = 0; m <= list_max; m++)
        {
            if (ch[n][m] != 0)
                ret[x++] = ch[n][m];
        }
    }

    ret[x] = '\0';

    return ret;
}