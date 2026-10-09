#include <string>

//双指针，左右如果是字母交换，不是则一直下一个
//时间复杂的：O(n)
class Solution 
{
    public:
        bool IsEnglish(char s)
        {
            if (s >= 'a' && s <= 'z')
                return true;

            if (s >= 'A' && s <= 'Z')
                return true;

            return false;
        }

        void Swap(char& s1, char& s2)
        {
            char temp = s1;
            s1 = s2;
            s2 = temp;
        }

        std::string reverseOnlyLetters(std::string s) 
        {
            int left = 0;
            int right = s.size() - 1;
            
            while (left < right)
            {
                while (left < right && !IsEnglish(s[left]))
                {
                    left++;
                }        

                while (left < right && !IsEnglish(s[right])) 
                {
                    right--;
                }

                Swap(s[left], s[right]);
                left++;
                right--;
            }

            return s;
        }
};