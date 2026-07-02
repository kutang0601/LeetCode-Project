#include <stdio.h>

//思路错误
//单纯比较然后返回首次出现的却忽略了可能会出现重复的
char* gcdOfStrings(char* str1, char* str2)
{
    char* ch = malloc(sizeof(char) *100000);
    char* pcur = ch;
    int arr1[26] = {0};
    int arr2[26] = {0};

    while (*str1 && *str2)
    {
        if (*str1 != *str2)
        {
            *ch = '\0';
            return ch;
        }
        else
        {
            if (arr1[*str1 - 'A'] == 0)
            {
                arr1[*str1 - 'A']++;
                *pcur = *str1;
                pcur++;
            }
        }
        str1++;
        str2++;
    }

    while (*str1)
    {
        if (arr1[*str1 - 'A'] == 0)
        {
            *ch = '\0';
            return ch;
        }    
        str1++;
    }

    while (*str2)
    {
        if (arr2[*str2 - 'A'] == 0)
        {
            *ch = '\0';
            return ch;
        }
        str2++;    
    }

    *pcur = '\0';
    return ch;
}

//寻找其本质就是最小的公约数
//既然是重复那么a和b拼接，b和a拼接肯定是相同的
int gcd(int a, int b) 
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

char* gcdOfStrings(char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char* cmp1 = malloc(len1 + len2 + 1);
    char* cmp2 = malloc(len1 + len2 + 1);

    strcpy(cmp1, str1);
    strcat(cmp1, str2);

    strcpy(cmp2, str2);
    strcat(cmp2, str1);

    if (strcmp(cmp1,cmp2))
        return "";
    
    int g = gcd(len1, len2);
    char* ret = malloc((g + 1) * sizeof(char));
    
    for(int i = 0; i < g; i++)
    {
        ret[i] = str1[i];
    }

    ret[g] = '\0';

    return ret;
}