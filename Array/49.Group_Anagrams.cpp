#include <algorithm>
#include <vector>
#include <string>

//超出时间限制
//时间复杂度：O(n² × k log k)
class Solution 
{
    public:
        std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) 
        {
            std::vector<std::vector<std::string>> ret;

            for (int n = 0; n < strs.size(); n++)
            {
                std::string temp = strs[n];
                std::sort(temp.begin(), temp.end());

                auto it = std::find_if(ret.begin(), ret.end(), [&temp](const std::vector<std::string>& row) 
                {
                    if (row.empty())
                        return false;

                    std::string sorted = row[0];
                    std::sort(sorted.begin(), sorted.end());
                    
                    return sorted == temp;
                });

                if (it != ret.end())
                {
                    ret[it - ret.begin()].push_back(strs[n]);
                }
                else 
                {
                    ret.push_back({});
                    ret.back().push_back(strs[n]); 
                }
            }

            return ret;
        }
};

//思路优化_询问AI(添加图)
//不使用find_if，直接对映复杂度降为O(1)
//时间复杂度：O(n × m logm)
#include <unordered_map>

class Solution1 
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) 
    {
        std::unordered_map<std::string, std::vector<std::string>> mp;

        for (int n = 0; n < strs.size(); n++)
        {
            std::string temp = strs[n];

            std::sort(temp.begin(), temp.end());

            mp[temp].push_back(strs[n]);
        }

        std::vector<std::vector<std::string>> ret;

        for (auto& pair : mp)
        {
            ret.push_back(pair.second);
        }

        return ret;
    }
};