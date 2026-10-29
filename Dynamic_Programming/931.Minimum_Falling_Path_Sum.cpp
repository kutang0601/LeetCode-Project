#include <vector>
#include <algorithm>

class Solution
{
    public:
        int minFallingPathSum(std::vector<std::vector<int>>& matrix)
        {
            int n = matrix.size();

            std::vector<std::vector<int>> dp(
                n, std::vector<int>(n, 0)
            );

            for (int j = 0; j < n; j++)
            {
                dp[0][j] = matrix[0][j];
            }

            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int min_prev = dp[i - 1][j];

                    if (j > 0)
                    {
                        min_prev = std::min(
                            min_prev, dp[i - 1][j - 1]
                        );
                    }

                    if (j + 1 < n)
                    {
                        min_prev = std::min(
                            min_prev, dp[i - 1][j + 1]
                        );
                    }

                    dp[i][j] = matrix[i][j] + min_prev;
                }
            }

            int ret = dp[n - 1][0];

            for (int j = 1; j < n; j++)
            {
                ret = std::min(ret, dp[n - 1][j]);
            }

            return ret;
        }
};
