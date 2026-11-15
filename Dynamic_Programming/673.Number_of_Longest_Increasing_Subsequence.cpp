#include <vector>

//动态规划，定义dp[i]为以i结尾的最长递增子序列，count[i]为以i结尾的最长递增子序列的个数
//时间复杂度：O(n ^ 2)
class Solution 
{
public:
    int findNumberOfLIS(std::vector<int>& nums) 
    {
        std::vector<int> dp(nums.size(), 0);
        std::vector<int> count(nums.size(), 0);
  
        dp[0] = 1;
        count[0] = 1;

        //外层遍历判断每个结尾的最长递增子序列
        for (int n = 0; n < nums.size(); n++)
        {
            //内层循环判断是否可以以nums[n]结尾以及结尾的话最长是多少
            for (int m = 0; m < n; m++)
            {
                if (nums[m] < nums[n])
                {
                    //如果找到新的最长递增子序列，那么就重新定义状态
                    if (dp[n] < dp[m] + 1)
                    {
                        count[n] = count[m];
                        dp[n] = dp[m] + 1;
                    }
                    //如果相等则加上count[m]
                    else if (dp[n] == dp[m] + 1)
                    {
                        count[n] += count[m];
                    }
                }
            }

            if (dp[n] == 0)
            {
                dp[n] = 1;
                count[n] = 1;
            }
        }

        int max_count = 0;
        int max_lenth = 0;

        //循环遍历寻找最长递增子序列个数 
        for (int i = 0; i < count.size(); i++)
        {
            if (dp[i] > max_lenth)
            {
                max_count = count[i];
                max_lenth = dp[i];
            }
            else if (dp[i] == max_lenth)
            {
                max_count += count[i];
            }
        }

        return max_count;
    }
};