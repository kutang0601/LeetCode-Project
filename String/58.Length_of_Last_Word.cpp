#include <string>

class Solution 
{
    public:
        int lengthOfLastWord(std::string s) 
        {
            if (s.empty())
                return 0;

            std::string ret;

            auto it = s.begin();

            while (it != s.end())
            {
                if (*it == ' ')
                {
                    while (it != s.end() && *it == ' ')
                    {
                        it++;
                    }

                    if (it != s.end())
                        ret.clear();

                    while (it != s.end() &&  *it != ' ')
                    {
                        ret += *it;
                        it++;
                    }
                }
                else
                {
                    while (it != s.end() &&  *it != ' ')
                    {
                        ret += *it;
                        it++;
                    }
                }
            }

            return ret.size();
        }
};