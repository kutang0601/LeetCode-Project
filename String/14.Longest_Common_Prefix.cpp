#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>


//找出最小的字符串长度，然后从每个字符串的第一个字符往前对比，遇到不同就返回ret字符串，如果全部相等则添加到ret最后
//时间复杂度：O(n * min_lenth)
class Solution
{
    public:
        std::string longestCommonPrefix(std::vector<std::string>& strs) 
        {
            if (strs.empty())
                return "";

            if (strs.size() == 1)
                return strs[0];

            int min_lenth = strs[0].size();
            
            for (size_t m = 1; m < strs.size(); m++)
            {
                min_lenth = std::min(min_lenth, static_cast<int>(strs[m].size()));
            }

            std::string ret;
            int n = 0;

            while (n < min_lenth)
            {
                for (int i = 0; i < strs.size() - 1; i++)
                {
                    if (strs[i][n] != strs[i + 1][n])
                    {
                        return ret;
                    }
                }

                ret.push_back(strs[0][n]);
                n++;
            }

            return ret;
        }
};