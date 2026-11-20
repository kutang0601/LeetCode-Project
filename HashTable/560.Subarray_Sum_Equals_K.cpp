#include <unordered_map>
#include <vector>

class Solution 
{
public:
    int subarraySum(std::vector<int>& nums, int k) 
    {
        std::unordered_map<int, int> storage;

        storage[0] = 1;

        int sum = 0;
        int ret = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (storage.find(sum - k) != storage.end())
            {
                ret += storage[sum - k];
            }

            storage[sum]++;
        }

        return ret;
    }
};