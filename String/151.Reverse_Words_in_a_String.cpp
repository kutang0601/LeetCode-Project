#include <string>

class Solution
{
public:
    std::string reverseWords(std::string s)
    {
        std::string ret;

        int i = s.size() - 1;

        while (i >= 0)
        {
            while (i >= 0 && s[i] == ' ')
            {
                i--;
            }

            if (i < 0)
            {
                break;
            }

            int end = i;

            while (i >= 0 && s[i] != ' ')
            {
                i--;
            }

            if (!ret.empty())
            {
                ret += ' ';
            }

            for (int j = i + 1; j <= end; j++)
            {
                ret += s[j];
            }
        }

        return ret;
    }
};