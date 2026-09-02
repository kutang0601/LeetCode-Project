#include <algorithm>
#include <vector>

//C++版本解答
class Solution 
{
    public:
        std::vector<std::vector<int>> ret;

        std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) 
        {
            if (intervals.size() == 1 || intervals.size() == 0)
                return intervals;

            std::sort(intervals.begin(), intervals.end(), 
            [](const auto& a, const auto& b)
            {
                return a[0] < b[0];
            });
            
            int len = 0;
            while(len < intervals.size())
            {
                ret.emplace_back();
                ret.back().push_back(intervals[len][0]);


                int left = intervals[len][1];
                while (len + 1 < intervals.size() && left >= intervals[len + 1][0])
                {
                    left = left > intervals[len + 1][1] ? left : intervals[len + 1][1];
                    len++;
                }

                ret.back().push_back(left);

                len++;
            }

            return ret;
        }
};