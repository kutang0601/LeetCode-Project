#include <vector>
#include <algorithm>

class Solution 
{
public:
    int maxArea(std::vector<int>& height) 
    {
        int left = 0;
        int right = height.size() - 1;
        int ret = 0;

        while (left < right)
        {
            int width = right - left;
            int h = std::min(height[left], height[right]);

            int area = width * h;

            ret = std::max(ret, area);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return ret;
    }
};