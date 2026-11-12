#include <string>
#include <vector>

//动态规划， dp[i][j]代表s1前i个字母与s2前j个字母转化为相同字符串所需要删除的最小ASCII值
//时间复杂度：O(n * m)
class Solution 
{
public:
    int minimumDeleteSum(std::string s1, std::string s2) 
    {
        std::vector<std::vector<int>> dp(s1.size() + 1, std::vector<int>(s2.size() + 1, 0));

        dp[0][0] = 0;
        
        for (int i = 1; i <= s1.size(); i++)
        {
            dp[i][0] = s1[i - 1] + dp[i - 1][0];
        }

        for (int j = 1; j <= s2.size(); j++)
        {
            dp[0][j] = s2[j - 1] + dp[0][j - 1];
        }

        for (int n = 1; n <= s1.size(); n++)
        {
            for (int m = 1; m <= s2.size(); m++)
            {
                //如果s1末尾单词和s2末尾单词不同，判断哪边删除后可以得到最小的ASCII值
                if (s1[n - 1] != s2[m - 1])
                {
                    dp[n][m] = std::min(dp[n - 1][m] + s1[n - 1], dp[n][m - 1] + s2[m - 1]);

                }
                else
                {
                    //相同则无需删除
                    dp[n][m] = dp[n - 1][m - 1];
                }
            }
        }

        return dp.back().back();
    }
};