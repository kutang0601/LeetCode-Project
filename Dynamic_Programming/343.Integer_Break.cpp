#include <vector>
#include <algorithm>

//动态规划，dp[n]为当前数字拆分整数最大乘积，然后枚举在他之间的数字，然后剩下的那个数字继续拆分与不拆分，当前值比较，拿到最大值
//时间复杂度：O(n ^ 2)
class Solution
{
    public:
        int integerBreak(int n)
        {
            std::vector<int> dp(n + 1, 0);

            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 1;

            for (int i = 3; i < n + 1; i++)
            {
                for (int j = 1; j < i; j++)
                {
                    int minus = i - j;

                    dp[i] = std::max(dp[i],std::max(j * minus, dp[j] * minus));
                }
            }

            return dp.back();
        }
};