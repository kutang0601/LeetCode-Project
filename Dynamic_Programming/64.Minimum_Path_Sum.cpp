#include <algorithm>
#include <vector>

//动态规划，比较上面和左面到达此位置的哪个步数最少，然后加上现在位置的数
//时间复杂度：O(n * m)
class Solution 
{
    public:
        int minPathSum(std::vector<std::vector<int>>& grid) 
        {
            std::vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid[0].size(), 0));
            
            dp[0][0] = grid[0][0];

            for (int n = 1; n < grid[0].size(); n++)
            {
                dp[0][n] = dp[0][n - 1] + grid[0][n];
            }


            for (int m = 1; m < grid.size(); m++)
            {
                dp[m][0] = dp[m - 1][0] + grid[m][0];
            }

            for (int i = 1; i < grid.size(); i++)
            {
                for (int j = 1; j < grid[0].size(); j++)
                {
                    dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }

            return dp.back().back();
        }
};