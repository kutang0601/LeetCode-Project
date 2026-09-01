#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(
        std::vector<std::string>& strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> mp;

        for (int i = 0; i < strs.size(); i++)
        {
            std::string key = strs[i];

            std::sort(key.begin(), key.end());

            mp[key].push_back(strs[i]);
        }

        std::vector<std::vector<std::string>> ret;

        for (auto& pair : mp)
        {
            ret.push_back(pair.second);
        }

        return ret;
    }
};