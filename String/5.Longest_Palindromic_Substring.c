#include <stdio.h>

char* longestPalindrome(char* s) 
{
    char* ch = (char*)malloc(sizeof(char) * 1001);
    if (!(*s))
    {
        ch[0] = '\0';
        return ch;
    }
    
    int start = 0;
    int lenth = strlen(s);
    int right = 0;
    int left = 0;
    int max_size = 1;
    int arr[2] = {0};
    int size = 1;
    while (s[start])
    {
        right = start + 1;
        left = start - 1;
        while (left >= 0 && right <= lenth - 1)
        {
            if (s[left] == s[right])
            {
                right++;
                left--;
                size += 2;
            }
            else
            {
                break;
            }
        }

        if (max_size < size)
        {
            max_size = size;
            arr[0] = left + 1;
            arr[1] = right - 1;
        }

        size = 0;

        left = start;
        right = start + 1;
        while (left >= 0 && right <= lenth - 1)
        {
            if (s[left] == s[right])
            {
                right++;
                left--;
                size += 2; 
            }
            else
            {
                break;
            }
        }

        if (max_size < size)
        {
            max_size = size;
            arr[0] = left + 1;
            arr[1] = right - 1;
        }
        size = 1;
        start++;
    }

    int x = 0;
    for (int n = arr[0]; n <= arr[1]; n++)
    {
        ch[x++] = s[n];
    }
    ch[x] = '\0';

    return ch;
}