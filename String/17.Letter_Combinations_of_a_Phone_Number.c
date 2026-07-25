/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char** letterCombinations(char* digits, int* returnSize) {
    char ch[100] = {0};
    for (int a = 0; a < 26; a++)
    {
        char x = 'a' + (char)a;
        ch[a] = x;
    }
    int arr[9] = {0, 3, 6, 9, 12, 15, 19, 22, 26};
    
    char** ret = (char**)malloc(sizeof(char*) * 10000);
    for (int b = 0; b < 10000; b++)
    {
        ret[b] = (char*)malloc(sizeof(char) * 5);
        ret[b][0] = '\0';
    }

    int lenth = strlen(digits);
    if (lenth == 1)
    {
        int lenth1 = 0;
        for (int c = arr[*digits - '2']; c < arr[*digits - '2' + 1]; c++)
        {
            ret[lenth1][0] = ch[c];
            ret[lenth1][1] = '\0';
            lenth1++; 
        }
        *returnSize = lenth1;
    }
    else if (lenth == 2)
    {  
        int lenth1 = 0;
        for (int a = arr[*digits - '2']; a < arr[*digits - '2' + 1]; a++)
        {
            char x1 = *(digits + 1);
            for (int b = arr[x1 - '2']; b < arr[x1 - '2' + 1]; b++)
            {
                ret[lenth1][0] = ch[a];
                ret[lenth1][1] = ch[b];
                ret[lenth1][2] = '\0';
                lenth1++;
            } 
        }
        *returnSize = lenth1;
    }
    else if (lenth == 3)
    {
        int lenth1 = 0;
        for (int a = arr[*digits - '2']; a < arr[*digits - '2' + 1]; a++)
        {
            char x1 = *(digits + 1);
            for (int b = arr[x1 - '2']; b < arr[x1 - '2' + 1]; b++)
            {
                char x2 = *(digits + 2);
                for (int c = arr[x2 - '2']; c < arr[x2 - '2' + 1]; c++)
                {
                    ret[lenth1][0] = ch[a];
                    ret[lenth1][1] = ch[b];
                    ret[lenth1][2] = ch[c];
                    ret[lenth1][3] = '\0';
                    lenth1++;
                }
            } 
        }
        *returnSize = lenth1;
    }
    else
    {
        int lenth1 = 0;
        for (int a = arr[*digits - '2']; a < arr[*digits - '2' + 1]; a++)
        {
            char x1 = *(digits + 1);
            for (int b = arr[x1 - '2']; b < arr[x1 - '2' + 1]; b++)
            {
                char x2 = *(digits + 2);
                for (int c = arr[x2 - '2']; c < arr[x2 - '2' + 1]; c++)
                {
                    char x3 = *(digits + 3);
                    for (int d = arr[x3 - '2']; d < arr[x3 - '2' + 1]; d++)
                    {
                        ret[lenth1][0] = ch[a];
                        ret[lenth1][1] = ch[b];
                        ret[lenth1][2] = ch[c];
                        ret[lenth1][3] = ch[d];
                        ret[lenth1][4] = '\0';
                        lenth1++;
                    }
                }
            } 
        }
        *returnSize = lenth1;
    }
    return ret;
}