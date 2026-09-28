#include <vector>

//遍历，拿到第一个和最后一个(违反限制)
//时间复杂度：O(n)
class Solution
{
    public:
        std::vector<int> searchRange(std::vector<int>& nums, int target)
        {
            std::vector<int> ret(2, -1);

            for (int n = 0; n < nums.size(); n++)
            {
                if (nums[n] == target)
                {
                    ret[0] = n;

                    while (n < nums.size() - 1 && nums[n] == nums[n + 1])
                    {
                        n++;
                    }

                    ret[1] = n;
                    break;
                }
            }

            return ret;
        }
};

//优化思路，二分查找解决
//时间复杂度：O(log(n))
class Solution1 
{
    public:
        std::vector<int> searchRange(std::vector<int>& nums, int target) 
        {
            std::vector<int> ret(2, -1);

            int left1 = 0;
            int right1 = nums.size() - 1;
            int mid1 = (left1 + right1) / 2;

            while (left1 <= right1)
            {
                mid1 = (left1 + right1) / 2;

                if (nums[mid1] > target)
                {
                    right1 = mid1 - 1;
                }
                else if (nums[mid1] < target) 
                {
                    left1 = mid1 + 1;
                }
                else 
                {
                    right1 = mid1 - 1;
                }
            }    

            if (left1 < nums.size() && nums[left1] == target)
            {
                ret[0] = left1;
            }

            int left2 = 0;
            int right2 = nums.size() - 1;
            int mid2 = (left2 + right2) / 2;

            while (left2 <= right2)
            {
                mid2 = (left2 + right2) / 2;

                if (nums[mid2] > target)
                {
                    right2 = mid2 - 1;
                }
                else if (nums[mid2] < target) 
                {
                    left2 = mid2 + 1;
                }
                else 
                {
                    left2 = mid2 + 1;
                }
            }    

            if (right2 >= 0 && nums[right2] == target)
                ret[1] = right2;

            return ret;
        }
};