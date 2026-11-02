#include <algorithm>
#include <vector>

//动态规划， 定义 dp[i][j] 为到达第 i 行第 j 列位置所需要的最小的点数和
//到达i行j列的位置只有三种，从左上，正上，右上，判断这三个哪个最小即可
//最后遍历最后一行dp，寻找到达最后一行的最小和，然后存储并返回
//时间复杂度：O(n ^ 2)
class Solution 
{
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) 
    {
        std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(matrix[0].size(), 0));

        for (int i = 0; i < matrix[0].size(); i++)
        {
            dp[0][i] = matrix[0][i];
        }

        for (int n = 1; n < matrix.size(); n++)
        {
            for (int m = 0; m < matrix[0].size(); m++)
            {
                if (m == 0)
                {
                    dp[n][m] = std::min(dp[n - 1][m] + matrix[n][m], dp[n - 1][m + 1] + matrix[n][m]);
                }
                else if (m == matrix[n].size() - 1)
                {
                    dp[n][m] = std::min(dp[n - 1][m] + matrix[n][m], dp[n - 1][m - 1] + matrix[n][m]);
                }
                else 
                {
                    dp[n][m] = std::min(dp[n - 1][m] + matrix[n][m], std::min(dp[n - 1][m - 1] + matrix[n][m], dp[n - 1][m + 1] + matrix[n][m]));
                }
            }
        }

        int ret = dp[matrix.size() - 1][0];

        for (int j = 0; j < matrix[0].size(); j++)
        {
            ret = std::min(ret, dp[matrix.size() - 1][j]);
        }
        
        return ret;
    }
};