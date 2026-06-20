#include <stido.h>

//单词规律
//https://leetcode.cn/problems/word-pattern/description/

bool wordPattern(char* pattern, char* s)
{
    int arr[26] = {0};
    char ch[26][3000] = {0};
    int count = 0;

    int x1 = strlen(pattern);
    int x2 = 0;

    char* pcur = s;
    while(*pcur)
    {
        if (*pcur == ' ')
            x2++;
        pcur++;
    }
    x2++;

    if (x2 != x1)
        return false;
    
    while(*pattern)
    {
        if(arr[(int)((*pattern) - 'a')] == 0)
        {
            while(*s != ' ' && *s != '\0')
            {
                ch[(int)((*pattern) - 'a')][count] = *s;
                count++;
                s++;
            }
            arr[(int)((*pattern) - 'a')] = 1;
            s++;
            ch[(int)((*pattern) - 'a')][count] = '\0';
        }
        else
        {
            while((*s != ' ' && *s != '\0') && ch[(int)((*pattern) - 'a')][count])
            {
                if (*s != ch[(int)((*pattern) - 'a')][count])
                    return false;
                s++;
                count++;
            }
            if ((*s != ' ' && *s != '\0') && !ch[(int)((*pattern) - 'a')][count])
                return false;
            if ((*s == ' ' || *s == '\0') && ch[(int)((*pattern) - 'a')][count])
                return false;
            s++;
        }
        count = 0;
        pattern++;
    }
    
    for(int a = 0; a < 25; a++)
    {
        for(int b = a + 1; b < 26; b++)
        {
            if (arr[a] == 1 && arr[b] == 1)
            {
                if (!strcmp(ch[a], ch[b]))
                return false;
            }
        }
    }

    return true;
}

int main()
{
    return 0;
}