#include <string>

class Solution 
{
    public:
        char findTheDifference(std::string s, std::string t) 
        {
            char ret = 0;

            for (int i = 0; i < s.size(); i++)
            {
                ret ^= s[i];
            }

            for (int i = 0; i < t.size(); i++)
            {
                ret ^= t[i];
            }

            return ret;
        }
};