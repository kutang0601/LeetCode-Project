#include <stdio.h>

int myAtoi(char* s) 
{
    if (*s == '\0')
        return 0;

    int sign = 1;
    int judge = 0;
    char ch[201] = {0};
    int lenth = 0;
    int judge_space = 0;
    int judge_zero = 0;
    while (*s)
    {
        if ((*s == ' ' && judge_space == 0) || (*s == '+' && judge == 0))
        {
            if (*s == '+')
            {
                judge_space++;  
                judge++;
            }
            s++;
        }
        else if (*s == '-' && judge == 0)
        {   
            ch[lenth] = *s;
            lenth++;
            sign = 0;
            judge++;
            judge_space++;
            s++;
        }
        else if (*s <= '9' && *s >= '0')
        {
            judge_space++;  
            judge++;
            if (*s != '0')
                judge_zero++;
            if (*s == '0' && judge_zero == 0)
            {
                s++;
                continue;
            }
            ch[lenth] = *s;
            lenth++;
            s++;
        }
        else
        {
            break;
        }
    }

    char int_max[] = "2147483647";
    char int_min[] = "-2147483648";
    ch[lenth] = '\0';

    int lenth1 = strlen(int_max);
    int lenth2 = strlen(int_min);

    char* pcur = ch;

    if (sign == 1)
    {
        if (lenth > lenth1)
        return 2147483647;
        else
        {
            if (strcmp(int_max, ch) <= 0 && lenth == lenth1)
            {
                return 2147483647;
            }
            else
            {
                int ret1 = 0;
                int lenth3 = lenth - 1;
                while (*pcur)
                {
                    ret1 += (*pcur - '0') * pow(10, lenth3);
                    lenth3--;
                    pcur++;
                }
                
                return ret1;
            }
        }
    }
    else
    {
        if (lenth > lenth2)
            return -2147483648;
        else
        {
            if (strcmp(int_min, ch) <= 0 && lenth == lenth2)
            {
                return -2147483648;
            }
            else
            {
                pcur++;
                int ret2 = 0;
                int lenth4 = lenth - 1;
                while (lenth4)
                {
                    ret2 += (*pcur - '0') * pow(10, lenth4 - 1);
                    lenth4--;
                    pcur++;
                }
                
                return ret2 * -1;
            } 
        }
    }

}



//代码优化
#include <limits.h>
#include <ctype.h>

int myAtoi(char* s) 
{
    long long ans = 0;
    int sign = 1;
    int i = 0;

    //跳过空格
    while (s[i] == ' ') 
        i++;

    //处理符号
    if (s[i] == '+' || s[i] == '-') 
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    //转换数字
    while (s[i] >= '0' && s[i] <= '9') 
    {
        ans = ans * 10 + (s[i] - '0');
        //提前检查溢出
        if (sign == 1 && ans > INT_MAX) 
        {
            return INT_MAX;
        }
        if (sign == -1 && ans > (long long)INT_MAX + 1) 
        {
            return INT_MIN;
        }
        i++;
    }

    return (int)(sign * ans);
}