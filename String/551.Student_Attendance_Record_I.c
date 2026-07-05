#include <stdio.h>

bool checkRecord(char* s) {
    char ch[26] = {0};
    char* r = s;
    while (*s)
    {
        if (*s == 'A')
        {
            ch[(int)(*s -'A')]++;
            if (ch[(int)(*s - 'A')] > 1)
            {
                return false;
            }
        }
        else if (*s == 'L')
        {
            if (s == r || *(s - 1) == 'L')
            {
                ch[(int)(*s - 'A')]++;
            }
            else
            {
                ch[(int)(*s - 'A')] = 1;
            }
            if (ch[(int)(*s - 'A')] >= 3)
                return false;
        }

        s++;
     }

     return true;
}