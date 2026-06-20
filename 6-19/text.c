#include <stdio.h>

//单词规律
//https://leetcode.cn/problems/word-pattern/description/


//比赛中的配对次数
//https://leetcode.cn/problems/count-of-matches-in-tournament/description/
int numberOfMatches(int n) {
    int all = 0;
    int x = n;
    while(x != 1)
    {
        all += x / 2;
        if (x % 2 == 1)
        {
            x /= 2;
            x++;
        }
        else 
        {
            x /= 2;
        }
    }
    return all;
}

int main()
{
    
    return 0;
}