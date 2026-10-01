#include <vector>
#include <algorithm>

class Solution
{
    public:
        int integerBreak(int n)
        {
            std::vector<int> dp(n + 1, 0);

            dp[2] = 1;

            for (int i = 3; i <= n; i++)
            {
                for (int j = 1; j < i; j++)
                {
                    dp[i] = std::max(dp[i], j * (i - j));
                    dp[i] = std::max(dp[i], j * dp[i - j]);
                }
            }

            return dp[n];
        }
};