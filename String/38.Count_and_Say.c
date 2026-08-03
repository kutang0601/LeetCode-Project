#include <stdlib.h>

char* countAndSay(int n) {
    char* ch1 = (char*)malloc(sizeof(char) * 10000);
    char* ch2 = (char*)malloc(sizeof(char) * 10000);

    int n1 = 0;
    int n2 = 0;

    int p1 = 0;
    int p2 = 0;

    int lenth[10] = {0};

    while (n--)
    {
        if (p1 == 0)
        {
            ch1[n1] = '1';
            n1++;
            p1++;
        }
        else
        {
            if (p1 == p2)
            {
                int lenth2 = 0;
                n1 = 0;

                while (lenth2 < n2)
                {
                    lenth[ch2[lenth2] - '0']++;
                    while(lenth2 < n2 - 1 && ch2[lenth2] == ch2[lenth2 + 1])
                    {
                        lenth2++;
                        lenth[ch2[lenth2] - '0']++;
                    }

                    ch1[n1] = lenth[ch2[lenth2] - '0'] + '0';
                    n1++;
                    ch1[n1] = ch2[lenth2];
                    n1++;
                    lenth[ch2[lenth2] - '0'] = 0;

                    lenth2++;
                }

                p1++;
            }
            else
            {
                int lenth1 = 0;
                n2 = 0;

                while (lenth1 < n1)
                {
                    lenth[ch1[lenth1] - '0']++;
                    while(lenth1 < n1 - 1 && ch1[lenth1] == ch1[lenth1 + 1])
                    {
                        lenth1++;
                        lenth[ch1[lenth1] - '0']++;
                    }

                    ch2[n2] = lenth[ch1[lenth1] - '0'] + '0';
                    n2++;
                    ch2[n2] = ch1[lenth1];
                    n2++;
                    lenth[ch1[lenth1] - '0'] = 0;
                
                    lenth1++;
                }

                p2++;
            }
        }
    }

    ch1[n1] = '\0';
    ch2[n2] = '\0';

    if (p1 > p2)
        return ch1;
    else
        return ch2;
}