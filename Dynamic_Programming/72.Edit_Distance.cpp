#include <vector>
#include <string>
#include <algorithm>

//动态规划思想
//时间复杂度：O(n * m)
class Solution 
{
    public:
        int minDistance(std::string word1, std::string word2) 
        {
            //创建统计表，其中dp[i][j]代表word1前i个字母到达word2前j个字母所需要的最小步数
            //其中dp[0][i]代表空字符串到达word2前i个字母最小步数
            //其中dp[i][0]代表word1前i个字母到达空字符串最小步数
            std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));

            //dp[n][0]的最小到达方式只能一直删
            for (int n = 0; n < word1.size() + 1; n++)
            {
                dp[n][0] = n;
            }

            //dp[0][m]的最小到达方式只能一直加
            for (int m = 0; m < word2.size() + 1; m++)
            {
                dp[0][m] = m;
            }

            //填充表格
            for (int p = 1; p < word1.size() + 1; p++)
            {
                for (int q = 1; q < word2.size() + 1; q++)
                {
                    //如果word1和word2后两个字符相同，那么它与word1前p-1到达word2前q-1最小步数相同
                    if (word1[p - 1] == word2[q - 1])
                    {
                        dp[p][q] = dp[p - 1][q - 1];
                    }      
                    else
                    {
                        //word1前p到达word2前q的最小步数只有三种方式
                        //1.首先是删除，那么word1前p-1已经到word2前q，它才能够删除，即dp[p - 1][q] + 1
                        //2.其次是添加，那么word1前p已经到word2前q-1，它才能够添加，即dp[p][q - 1] + 1
                        //3.最后是改变，那么word1前p-1已经到word2前q-1，它才能够改变，即dp[p - 1][q - 1] + 1
                        dp[p][q] = std::min({dp[p - 1][q] + 1, dp[p][q - 1] + 1, dp[p - 1][q - 1] + 1});
                    }          
                }
            }

            return dp[word1.size()][word2.size()];
        }
};