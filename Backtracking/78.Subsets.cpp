#include <vector>

class Solution 
{
public:
    std::vector<std::vector<int>> ret;
    std::vector<int> part;

    void backtrace(std::vector<int>& nums, int start)
    {
        ret.push_back(part);

        for (int n = start; n < nums.size(); n++)
        {
            part.push_back(nums[n]);

            backtrace(nums, n + 1);

            part.pop_back();
        }
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        backtrace(nums, 0);

        return ret;
    }

};