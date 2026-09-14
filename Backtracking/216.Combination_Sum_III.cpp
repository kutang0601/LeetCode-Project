#include <vector>

//回溯
//时间复杂度：O(k * C(9, k))
class Solution 
{
    public:
        std::vector<std::vector<int>> ret;
        std::vector<int> temp;

        void BackTrace(int& k, int& n, int count, int now, int begin)
        {
            if (count == k && now == n)
            {
                ret.push_back(temp);
                return;
            }

            for (int it = begin; it <= 9; it++)
            {
                if (count <= k)
                {
                    temp.push_back(it);

                    BackTrace(k, n, count + 1, now + it, it + 1);

                    temp.pop_back();
                }
                else 
                {
                    return;
                }
            }
            
        }

       std::vector<std::vector<int>> combinationSum3(int k, int n) 
        {
            BackTrace(k, n, 0, 0, 1);

            return ret;
        }
};