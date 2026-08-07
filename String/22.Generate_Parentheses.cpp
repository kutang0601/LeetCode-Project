#include <string>
#include <vector>


class Solution {
public:
    void backtrack(std::vector<std::string>& ret, std::string ch, int left, int right, int n)
    {

        if (left == n && right == n)
        {
            ret.push_back(ch);
        }

        if (left < n)
        {
            ch += '(';
            backtrack(ret, ch, left + 1, right, n);
            ch.pop_back();
        }

        if (left > right)
        {
            ch += ')';
            backtrack(ret, ch, left,right + 1, n);
            ch.pop_back();
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ret;

        std::string ch = "";

        backtrack(ret, ch, 0, 0, n);

        return ret;
    }
};