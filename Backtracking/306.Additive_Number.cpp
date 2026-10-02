#include <string>

class Solution
{
public:
    std::string add(std::string a, std::string b)
    {
        std::string ret;

        int i = a.size() - 1;
        int j = b.size() - 1;
        int store = 0;

        while (i >= 0 || j >= 0 || store)
        {
            int sum = store;

            if (i >= 0)
            {
                sum += a[i] - '0';
                i--;
            }

            if (j >= 0)
            {
                sum += b[j] - '0';
                j--;
            }

            ret.insert(0, 1, sum % 10 + '0');
            store = sum / 10;
        }

        return ret;
    }

    bool check(std::string s, int first, int second)
    {
        int n = s.size();

        std::string a = s.substr(0, first);
        std::string b = s.substr(first, second - first);

        int pos = second;
        int count = 2;

        while (pos < n)
        {
            std::string c = add(a, b);

            if (pos + c.size() > n)
                return false;

            if (s.substr(pos, c.size()) != c)
                return false;

            pos += c.size();
            a = b;
            b = c;
            count++;
        }

        return count >= 3;
    }

    bool isAdditiveNumber(std::string s)
    {
        int n = s.size();

        for (int first = 1; first < n; first++)
        {
            if (first > 1 && s[0] == '0')
                break;

            for (int second = first + 1; second < n; second++)
            {
                if (second - first > 1 && s[first] == '0')
                    break;

                if (check(s, first, second))
                    return true;
            }
        }

        return false;
    }
};