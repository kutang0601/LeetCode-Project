#include <vector>
#include <algorithm>

class Solution 
{
    public:
        void sortColors(std::vector<int>& nums) 
        {
            int left = 0;
            int right = nums.size() - 1;
            int i = 0;

            while (i <= right) 
            {
                if (nums[i] == 0) 
                {
                    std::swap(nums[i], nums[left]);
                    left++;
                    i++;
                }
                else if (nums[i] == 1) 
                {
                    i++;
                }
                else 
                {
                    std::swap(nums[i], nums[right]);
                    right--;
                }
            }
        }
};