#include <vector>

//动态规划， 定义 dp[i][j] 为到达第 i 行第 j 列位置所需要的最小的点数和
//到达i行j列的位置只有三种，从右上，左上，判断这三个哪个最小即可
//最后遍历最后一行dp，寻找到达最后一行的最小和，然后存储并返回
//时间复杂度：O(n ^ 2)
class Solution 
{
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) 
    {
        std::vector<std::vector<int>> dp(triangle.size());

        for (int n = 0; n < triangle.size(); n++)
        {
            dp[n].resize(triangle[n].size(), 0);
        }
        
        dp[0][0] = triangle[0][0];

        for (int n = 1; n < triangle.size(); n++)
        {
            for (int m = 0; m < triangle[n].size(); m++)
            {
                if (m == 0)
                {
                    dp[n][m] = dp[n - 1][m] + triangle[n][m];
                }
                else if (m == triangle[n].size() - 1)
                {
                    dp[n][m] = dp[n - 1][m - 1] + triangle[n][m];
                }
                else 
                {
                    dp[n][m] = std::min(dp[n - 1][m] + triangle[n][m], dp[n - 1][m - 1] + triangle[n][m]);
                }
            }
        }

        int ret = dp[triangle.size() - 1][0];

        for (int j = 0; j < triangle[triangle.size() - 1].size(); j++)
        {
            ret = std::min(ret, dp[triangle.size() - 1][j]);
        }
        
        return ret;
    }
};