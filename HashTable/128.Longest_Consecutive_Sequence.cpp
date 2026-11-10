#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution
{
public:
    int longestConsecutive(std::vector<int>& nums)
    {
        std::unordered_set<int> num_set(nums.begin(), nums.end());

        int ret = 0;

        for (int num : num_set)
        {
            if (num_set.find(num - 1) == num_set.end())
            {
                int count = 1;
                int current = num;

                while (num_set.find(current + 1) != num_set.end())
                {
                    current++;
                    count++;
                }

                ret = std::max(ret, count);
            }
        }

        return ret;
    }
};
