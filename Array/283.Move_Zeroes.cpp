#include <vector>
#include <utility>

class Solution 
{
public:
    void moveZeroes(std::vector<int>& nums) 
    {
        int slow = 0;

        for (int fast = 0; fast < nums.size(); fast++)
        {
            if (nums[fast] != 0)
            {
                std::swap(nums[slow], nums[fast]);
                slow++;
            }
        }
    }
};
