#include <stdlib.h>
#include <string.h>


char* multiply(char* num1, char* num2) 
{
    char* ret = (char*)malloc(sizeof(char) * 1000);
    memset(ret, 0, sizeof(ret));
    int carry = 0;

    if (*num1 == '0' || *num2 == '0')
        return "0\0";

    int n1 = strlen(num1);
    int n2 = strlen(num2);
    int o = 0;

    for (int a = n1 - 1; a >= 0; a--)
    {
        int p = o;
        o++;
        for (int b = n2 - 1; b >= 0; b--)
        {
            int new = ret[p] == '\0' ? (num1[a] - '0') * (num2[b] - '0') + carry : (num1[a] - '0') * (num2[b] - '0') + carry + (ret[p] - '0');
            if (new > 9)
            {
                carry = new % 10;
                new /= 10;
                int tmp = carry;
                carry = new;
                new = tmp;
            }
            else
            {
                carry = 0;
            }

            ret[p] = new + '0';
            p++;
            if (b == 0 && carry != 0)
            {
                ret[p] = carry + '0';
                carry = 0;
            }
        }
    }

    int right = strlen(ret)- 1;
    int left = 0;
    while(left <= right)
    {
        char tmp = ret[left];
        ret[left] = ret[right];
        ret[right] = tmp;
        left++;
        right--;
    }

    return ret;
}