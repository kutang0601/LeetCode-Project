#include <string>
#include <vector>

class Solution
{
    public:
        std::string longestCommonPrefix(std::vector<std::string>& strs)
        {
            std::string ret;

            if (strs.empty())
            {
                return ret;
            }

            for (int i = 0; i < static_cast<int>(strs[0].size()); ++i)
            {
                char ch = strs[0][i];

                for (int j = 1; j < static_cast<int>(strs.size()); ++j)
                {
                    if (i >= static_cast<int>(strs[j].size()) || strs[j][i] != ch)
                    {
                        return ret;
                    }
                }

                ret += ch;
            }

            return ret;
        }
};
