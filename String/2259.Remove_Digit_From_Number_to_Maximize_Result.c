#include <stdio.h>

//贪心求解
char* removeDigit(char* number, char digit) {
    int len = strlen(number);
    char* ch = malloc(len + 1);
    char* pcur = ch;
    int n = 0;
    int last = -1;
    int p = 0;

    while(*number)
    {
        if (*number == digit)
        {
            last = p;
            if (((*number < *(number + 1)) || *(number + 1) == '\0') && n == 0)
            {
                n++;
                number++;
                continue;
            }
            else
            {
                *pcur = *number;   
                pcur++;
            }
        }
        else
        {
            *pcur = *number;   
            pcur++;
        }
        number++;
        p++;
    }
    if (n == 0)
    {
        for (int x = last; x < len - 1; x++)
        {
            ch[x] = ch[x + 1];
        }
        ch[len - 1] = '\0';
    }

    *pcur = '\0';

    return ch;
}

//代码优化
char* removeDigit(char* number, char digit)
{
    int len = strlen(number);
    int index = 0;

    for (int i = 0; i < len; i++)
    {
        if (number[i] == digit)
        {
            index = i;

            if (i + 1 < len && number[i + 1] > digit)
                break;
        }
    }

    char* res = (char*)malloc(len); 
    int k = 0;

    for (int i = 0; i < len; i++)
    {
        if (i != index)
            res[k++] = number[i];
    }

    res[k] = '\0';
    return res;
}