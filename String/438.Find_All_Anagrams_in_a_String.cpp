#include <string>
#include <vector>

class Solution 
{
public:
    std::vector<int> findAnagrams(std::string s, std::string p) 
    {
        std::vector<int> ret;

        if (s.size() < p.size())
        {
            return ret;
        }

        std::vector<int> need(26, 0);
        std::vector<int> window(26, 0);

        for (int i = 0; i < p.size(); i++)
        {
            need[p[i] - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < s.size(); right++)
        {
            window[s[right] - 'a']++;

            if (right - left + 1 > p.size())
            {
                window[s[left] - 'a']--;
                left++;
            }

            if (right - left + 1 == p.size() && window == need)
            {
                ret.push_back(left);
            }
        }

        return ret;
    }
};