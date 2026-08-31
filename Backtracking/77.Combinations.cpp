#include <vector>

//回溯思想
//时间复杂度:O(C(n,k)×k)
class Solution 
{
    public:
        std::vector<std::vector<int>> ret;
        std::vector<int> temp;

        void backtrace(int n, int k, int now)
        {
            if (temp.size() == k)
            {
                ret.push_back(temp);
            }

            for (int it = now; it <= n; it++)
            {
                temp.push_back(it);

                backtrace(n, k, it + 1);

                temp.pop_back();
            }
        }

        std::vector<std::vector<int>> combine(int n, int k) 
        {
            backtrace(n, k, 1);

            return ret;
        }
};