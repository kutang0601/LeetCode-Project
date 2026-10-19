#include <string>
#include <unordered_map>

class Solution 
{
    public:
        char findTheDifference(std::string s, std::string t) 
        {
            std::unordered_map<char, int> judge;

            for (auto& it : s)
            {
                auto ch = judge.find(it);
                
                if (ch != judge.end())
                {
                    judge[it]++;
                }
                else
                {
                    judge[it] = 1;
                }
            }

            for (auto& it : t)
            {
                auto ch = judge.find(it);
                
                if (ch != judge.end())
                {
                    judge[it]--;
                }
                else
                {
                    judge[it] = -1;
                }
            }

            for (const auto& [k, v]: judge)
            {
                if (v == -1)
                    return k;
            }

            return 0;
        }
};