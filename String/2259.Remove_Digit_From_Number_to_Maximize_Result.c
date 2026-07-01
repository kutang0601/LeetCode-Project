#include <stdio.h>

char* removeDigit(char* number, char digit)
{
    int len = strlen(number);
    int index = 0;

    // 找删除位置
    for (int i = 0; i < len; i++)
    {
        if (number[i] == digit)
        {
            index = i;

            // 如果后面更大，就优先删这里
            if (i + 1 < len && number[i + 1] > digit)
                break;
        }
    }

    char* res = (char*)malloc(len); // len-1 + '\0'
    int k = 0;

    for (int i = 0; i < len; i++)
    {
        if (i != index)
            res[k++] = number[i];
    }

    res[k] = '\0';
    return res;
}