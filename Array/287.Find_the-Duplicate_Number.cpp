#include <algorithm>
#include <vector>

//排序后，这个数字和下一个相等，则返回这个数
//时间复杂度：O(n * log(n))
class Solution 
{
    public:
        int findDuplicate(std::vector<int>& nums) 
        {
            std::sort(nums.begin(), nums.end());
            
            for(int n = 0; n < nums.size() - 1; n++)
            {
                if (nums[n] == nums[n + 1])
                    return nums[n];
            }

            return 0;
        }
};

//思路优化
//floyd判圈算法(快慢指针判圈)
//因为题目给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），所以可以把每个下标指向的数字，来当作下一个下标，然后使用floyd算法
//例如 nums[0] = 7，那么下一个则是nums[7]，以此类推
//时间复杂度：O(n)
class Solution1 
{
    public:
        int findDuplicate(std::vector<int>& nums) 
        {
            int slow = 0;
            int fast = 0;

            //在环内寻找相同位置
            do 
            {
                slow = nums[slow];
                fast = nums[fast];
                fast = nums[fast];
            } while (fast != slow);

            int next = 0;

            //两个同时走，相遇位置即为环的开始位置
            //由于两个及两个以上指向同一个位置，一个在环外，一个在环内，所以环开始的位置为重复的数字
            while (next != slow)
            {
                slow = nums[slow];
                next = nums[next];
            }

            return slow;
        }
};