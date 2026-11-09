#include <algorithm>
#include <string>
#include <vector>

//动态规划，定义二维数组dp，其中dp[i][j]为从下标i->j的单词构成的最大回文单词
//时间复杂度：O(n ^ 2)
class Solution 
{
public:
    int longestPalindromeSubseq(std::string s) 
    {
        std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));

        //对角线上单词均为一个单词，初始化dp为1
        for (int i = 0; i < s.size(); i++)
        {
            dp[i][i] = 1;
        }

        //外层循环 n 从下往上（因为需使用到dp[n + 1])
        //内层循环 m 从左往右 (因为需使用到dp[m - 1])
        for (int n = s.size() - 1; n >= 0; n--)
        {
            for (int m = n + 1; m < s.size(); m++)
            {
                if (s[n] == s[m])
                {
                    //如果左右两个单词相等，+2 即可
                    dp[n][m] = dp[n + 1][m - 1] + 2;
                }
                else
                {
                    //删除左边或者删除右边，然后判断哪个最大
                    dp[n][m] = std::max(dp[n + 1][m], dp[n][m - 1]);
                }
            }
        }

        return dp[0][s.size() - 1];
    }
};