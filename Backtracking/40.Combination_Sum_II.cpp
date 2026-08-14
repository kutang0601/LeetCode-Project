#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> ret;
    std::vector<int> temp;

    int x = 0;

    template <typename Iterator>
    void backtrace(std::vector<int>& candidate, int now, int target, Iterator begin)
    {
        for (auto n = begin; n < candidate.end(); n++)
        {
            if (n > begin && *n == *(n - 1))
                continue;

            if (now + *n > target)
                break;

            now += *n;
            temp.push_back(*n);

            if (now == target)
            {
                ret.push_back(temp);
            }
            else
            {
                backtrace(candidate, now, target, n + 1);
            }

            temp.pop_back();
            now -= *n;
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());

        auto begin = candidates.begin();

        backtrace(candidates, x, target, begin);

        return ret;
    }
};