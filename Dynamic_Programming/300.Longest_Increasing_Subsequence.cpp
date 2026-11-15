#include <vector>
#include <algorithm>

//动态规划，定义dp[i]为以i结尾，能够达到的最长递增子序列
class Solution
{
public:
    int lengthOfLIS(std::vector<int>& nums)
    {
        std::vector<int> dp(nums.size(), 0);

        dp[0] = 1;

        //外层遍历判断每个结尾的最长递增子序列
        for (int n = 0; n < nums.size(); n++)
        {
            //内层循环判断是否可以以nums[n]结尾以及结尾的话最长是多少
            for (int m = 0; m < n; m++)
            {
                if (nums[m] < nums[n])
                {
                    dp[n] = std::max(dp[n], dp[m] + 1);
                }
            }

            if (dp[n] == 0)
                dp[n] = 1;
        }

        int max_ret = 0;

        //遍历dp寻找最大
        for (int i = 0; i < dp.size(); i++)
        {
            if (max_ret < dp[i])
            {
                max_ret = dp[i];
            }
        }

        return max_ret;
    }
};
