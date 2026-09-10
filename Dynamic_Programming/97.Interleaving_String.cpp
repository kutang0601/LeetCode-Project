#include <string>
#include <vector>

class Solution 
{
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) 
    {
        if (s1.size() + s2.size() != s3.size())
            return false;

        int m = s1.size();
        int n = s2.size();

        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 && j == 0)
                    continue;

                if (i > 0 && dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                    dp[i][j] = true;

                if (j > 0 && dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = true;
            }
        }

        return dp[m][n];
    }
};