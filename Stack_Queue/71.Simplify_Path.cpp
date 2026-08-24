#include <string>
#include <vector>

//先根据'/'划分，然后根据每种符号处理对应情况，最后添加组合
//时间复杂度：O(n)
class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> ch;
        std::string temp;

        for (auto it : path)
        {
            if (it != '/')
            {
                temp.push_back(it);
                continue;
            }
            if (it == '/' || it + 1 == '\0')
            {
                if (temp == "")
                {

                }
                else if (temp == ".")
                {

                }
                else if (temp == "..")
                {
                    if (!ch.empty())
                    {
                        ch.pop_back();
                    }
                }
                else 
                {
                    ch.push_back(temp);
                }
                temp.clear();
            }
        }
        
        if (temp == "")
        {

        }
        else if (temp == ".")
        {

        }
        else if (temp == "..")
        {
            if (!ch.empty())
            {
                ch.pop_back();
            }
        }
        else 
        {
            ch.push_back(temp);
        }
        temp.clear();

        std::string ret;
        for (auto it : ch)
        {
            ret += '/';
            ret += it;
        }

        if (ret == "")
            ret += '/';

        return ret;
    }
};