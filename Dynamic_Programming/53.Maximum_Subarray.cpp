#include <algorithm>
#include <vector>

class Solution 
{
    public:
        // 动态规划思想
        int maxSubArray(std::vector<int>& nums) 
        {
            int ret = nums[0];
            int max = nums[0];

            for (auto it = nums.begin() + 1; it < nums.end(); it++)
            {
                max = std::max(*it, max + *it);   
                ret = std::max(ret, max);             
            }

            return ret;
        }
};


