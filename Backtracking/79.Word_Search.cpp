#include <vector>
#include <string>

class Solution {
public:
    bool backtrace(const std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& judge, const std::string& word, int list, int conlum, int nowlenth)
    {
        if (nowlenth == word.size())
            return true;
        
        char ch = word[nowlenth];
        
        if (conlum > 0 && ch == board[list][conlum - 1] && judge[list][conlum - 1] == false)
        {
            judge[list][conlum - 1] = true;
            if (backtrace(board, judge, word, list, conlum - 1, nowlenth + 1))
                return true;
            judge[list][conlum - 1] = false;
        }

        if (conlum < board[list].size() - 1 && ch == board[list][conlum + 1] && judge[list][conlum + 1] == false)
        {
            judge[list][conlum + 1] = true;
            if (backtrace(board, judge, word, list, conlum + 1, nowlenth + 1))
                return true;
            judge[list][conlum + 1] = false;
        }

        if (list > 0 && ch == board[list - 1][conlum] && judge[list - 1][conlum] == false)
        {
            judge[list - 1][conlum] = true;
            if (backtrace(board, judge, word, list - 1, conlum, nowlenth + 1))
            {
                return true;
            }
            judge[list - 1][conlum] = false;
        }

        if (list < board.size() - 1 && ch == board[list + 1][conlum] && judge[list + 1][conlum] == false)
        {
            judge[list + 1][conlum] = true;
            if (backtrace(board, judge, word, list + 1, conlum, nowlenth + 1))
            {
                return true;
            }
            judge[list + 1][conlum] = false;
        }

        return false;
    }

    //回溯，不断判断四周的数字是否和下一个词相等
    //时间复杂度：O(m * n * 3 ^ l)
    bool exist(std::vector<std::vector<char>>& board, std::string word) 
    {
        std::vector<std::vector<bool>> judge(board.size(), std::vector<bool>(board[0].size(), false));

        for (auto itst = 0; itst < board.size(); itst++)
        {
            for (auto itnd = 0; itnd < board[itst].size(); itnd++)
            {
                if (board[itst][itnd] == word[0])
                {
                    judge[itst][itnd] = true;
                    bool ret = backtrace(board, judge, word, itst, itnd, 1);
                    judge[itst][itnd] = false;

                    if (ret)
                        return true;
                }
            }
        }
        
        return false;
    }
};