#include <stdio.h>

//采用动态滑动数组，当有重复时left不断向左移动直至无重复
//判别重复参用数组下标来记录
int lengthOfLongestSubstring(char* s) {
    int left = 0;
    int right = 0;
    int arr[200] = {0};
    int max = 0;

    while(s[right])
    {
        if(arr[(int)s[right]] < 1)
        {
            arr[(int)s[right]]++;
        }
        else
        {
            while(arr[(int)s[right]] >= 1)
            {
                arr[(int)s[left]]--;
                left++;
            }
            arr[(int)s[right]]++;
        }

        right++;
        max = max > (right - left) ? max : right - left;
    }

    return max;
}