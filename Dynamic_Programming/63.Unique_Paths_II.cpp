#include <vector>

//动态规划，要想知道第[m][n]位置，就需要知道上一个和前一个，两个相加
//到达第一行和第一列的只有一种方法，如果在第一列或者第一行的话，那么他后面的就没办法到达
//如果是障碍的话，那么到达这里的方式就是0
//时间复杂度：O(n * m)
class Solution 
{
    public:
        int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) 
        {
            std::vector<std::vector<int>> dp(obstacleGrid.size(), std::vector<int>(obstacleGrid[0].size(), 0));

            for (int n1 = 0; n1 < obstacleGrid[0].size(); n1++)
            {
                if (obstacleGrid[0][n1] == 0)
                {
                    dp[0][n1] = 1;
                }
                else 
                {
                    while (n1 < obstacleGrid[0].size())
                    {
                        dp[0][n1] = 0;
                        n1++;
                    }
                }
            }

            for (int m1 = 0; m1 < obstacleGrid.size(); m1++)
            {
                if (obstacleGrid[m1][0] == 0)
                {
                    dp[m1][0] = 1;
                }
                else 
                {
                    while (m1 < obstacleGrid.size())
                    {
                        dp[m1][0] = 0;
                        m1++;
                    }
                }
            }

            for (int p = 1; p < obstacleGrid.size(); p++)
            {
                for (int q = 1; q < obstacleGrid[0].size(); q++)
                {
                    if (obstacleGrid[p][q] == 1)
                    {
                        dp[p][q] = 0;
                    }
                    else 
                    {
                        dp[p][q] = dp[p - 1][q] + dp[p][q - 1];
                    }
                }
            }

            return dp.back().back();
        }
};