#include <algorithm>
#include <vector>

//用一个数组记录能否到达，如果非0,则该位置可以到达
//时间复杂度：O(n ^ 2)
class Solution 
{
    public:
        bool canJump(std::vector<int>& nums) 
        {
            std::vector<int> dp(nums.size(), 0);

            if (nums.size() == 1)
                return true;

            if (nums.empty() || nums[0] == 0)
                return false;
            else
            {
                int x = nums[0];
                int p = 1;
                while (x-- && p < nums.size())
                {
                    dp[p]++;
                    p++;
                }
            }

            for (int n = 1; n < nums.size() - 1; n++)
            {
                if (dp[n] != 0 && nums[n] != 0)
                {
                    int x = nums[n];
                    int p = n + 1;
                    while (x-- && p < nums.size())
                    {
                        dp[p]++;
                        p++;
                    }
                }
            }
            if (dp.back() != 0)
                return true;
            
            return false;
        }
};

//优化思路
//判断最大能够到达的位置
//时间复杂度：O(n)
class Solution2 
{
    public:
        bool canJump(std::vector<int>& nums) 
        {
            int max_location = 0;

            for (int n = 0; n <= max_location && n < nums.size(); n++)
            {
                max_location = std::max(max_location, n + nums[n]);
            }

            if (max_location >= nums.size() - 1)
                return true;

            return false;
        }
};