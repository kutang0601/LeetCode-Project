#include <stdio.h>

//滑动数组解题
int countGoodSubstrings(char* s) 
{
    int arr[200] = {0};
    int right = 0;
    int left = 0;
    int count = 0;

    if (strlen(s) < 3)
        return 0;

    while(right <= 2)
    {
        arr[(int)s[right]]++;
        right++;
    }

    right--;
    
    if (arr[(int)s[right]] == 1 && arr[(int)s[left]] == 1 && arr[(int)s[left + 1]] == 1)
        count++;


    while(s[right + 1])
    {
        arr[(int)s[left]]--;
        left++;
        right++;
        arr[(int)s[right]]++;
        if (arr[(int)s[right]] == 1 && arr[(int)s[left]] == 1 && arr[(int)s[left + 1]] == 1)
            count++;
    }   
    
    return count;
}