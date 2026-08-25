#include <vector>

//动态规划，要想知道第[m][n]位置，就需要知道上一个和前一个，两个相加
//到达第一行和第一列的只有一种方法
//时间复杂度：O(n * m)
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        for (int n1 = 0; n1 < n; n1++)
        {
            dp[0][n1] = 1;
        }
        for (int m1 = 0; m1 < m; m1++)
        {
            dp[m1][0] = 1;
        }

        for (int p = 1; p < m; p++)
        {
            for (int q = 1; q < n; q++)
            {
                dp[p][q] = dp[p - 1][q] + dp[p][q - 1];
            }
        }

        return dp.back().back();
    }
};