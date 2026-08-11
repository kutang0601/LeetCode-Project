//递归+回溯
//复杂度过高，超出时间限制
class Solution {
public:
    void recursion(int& ret, int now, int target)
    {
        if (now > target)
            return;
        if (now == target)
        {
            ret++;
            return;
        }
        now += 1;
        recursion(ret, now, target);
        now -= 1;

        now += 2;
        recursion(ret, now, target);
        now -= 2;
    }

    int climbStairs(int n) 
    {
        int ret = 0;

        recursion(ret, 0, n);

        return ret;
    }
};

//动态规划
class Solution_ {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        int n1 = 1;
        int n2 = 1;

        n -= 1;

        while(n--)
        {
            int tmp = n1 + n2;
            n1 = n2;
            n2 = tmp;
        }
        return n2;
    }
};