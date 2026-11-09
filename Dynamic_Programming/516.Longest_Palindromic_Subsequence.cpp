#include <algorithm>
#include <string>
#include <vector>

class Solution 
{
public:
    int longestPalindromeSubseq(std::string s) 
    {
        std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));

        for (int i = 0; i < s.size(); i++)
        {
            dp[i][i] = 1;
        }

        for (int n = 0; n < s.size(); n++)
        {
            for (int m = n + 1; m < s.size(); m++)
            {
                if (s[n] == s[m])
                {
                    dp[n][m] = dp[n + 1][m - 1] + 2;
                }
                else
                {
                    dp[n][m] = std::max(dp[n + 1][m], dp[n][m - 1]);
                }
            }
        }

        return dp[0][s.size() - 1];
    }
};