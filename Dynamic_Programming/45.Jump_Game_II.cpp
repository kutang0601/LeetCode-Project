#include <algorithm>
#include <vector>

//时间复杂度:O(n)
class Solution 
{
    public:
        int jump(std::vector<int>& nums) 
        {
            if (nums.size() == 1)
                return 0;

            int max_location = 0;
            int left = 0;
            int ret = 0;

            for (int n = 0; n <= max_location && n < nums.size(); n++)
            {
                max_location = std::max(max_location, n + nums[n]);

                if (n == left)
                {
                    ret++;
                    left = max_location;
                    
                    if (max_location >= nums.size() - 1)
                    {
                        break;
                    }
                }
            }

            return ret;
        }
};
