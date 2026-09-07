#include <algorithm>
#include <vector>

//定义一个右边界值，如果现在right到达右边值，那么让right等于现在能够到达最远的距离
//时间复杂度:O(n)
class Solution 
{
    public:
        int jump(std::vector<int>& nums) 
        {
            if (nums.size() == 1)
                return 0;

            int max_location = 0;
            int right = 0;
            int ret = 0;

            for (int n = 0; n < nums.size() && n <= max_location; n++)
            {
                max_location = std::max(nums[n] + n, max_location);

                if (n == right)
                {
                    ret++;

                    right = max_location;
                    
                    if (max_location >= nums.size() - 1)
                        break;
                }    
            }

            return ret;
        }
};
