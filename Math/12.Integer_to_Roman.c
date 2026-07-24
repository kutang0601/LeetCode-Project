#include <stdio.h>

char* intToRoman(int num) {
    char* ch = (char*)malloc(sizeof(char) * 1000);

    int n = num;
    int x = 0;
    while (n)
    {
        if (n >= 1000)
        {
            n -= 1000;
            ch[x] = 'M';
        }
        else if (n >= 900)
        {
            n -= 900;
            ch[x] = 'C';
            x++;
            ch[x] = 'M';
        }
        else if (n >= 500)
        {
            n -= 500;
            ch[x] = 'D';
        }
        else if (n >= 400)
        {
            n -= 400;
            ch[x] = 'C';
            x++;
            ch[x] = 'D';
        }
        else if (n >= 100)
        {
            n -= 100;
            ch[x] = 'C';
        }
        else if (n >= 90)
        {
            n -= 90;
            ch[x] = 'X';
            x++;
            ch[x] = 'C';
        }
        else if (n >= 50)
        {
            n -= 50;
            ch[x] = 'L';
        }
        else if (n >= 40)
        {
            n -= 40;
            ch[x] = 'X';
            x++;
            ch[x] = 'L';
        }
        else if (n >= 10)
        {
            n -= 10;
            ch[x] = 'X';
        }
        else if (n >= 9)
        {
            n -= 9;
            ch[x] = 'I';
            x++;
            ch[x] = 'X';
        }
        else if (n >= 5)
        {
            n -= 5;
            ch[x] = 'V'; 
        }
        else if (n >= 4)
        {
            n -= 4;
            ch[x] = 'I';
            x++;
            ch[x] = 'V';
        }
        else 
        {
            n -= 1;
            ch[x] = 'I';
        }

        x++;
    }

    ch[x] = '\0';
    
    return ch;
}

//优化思路，减少代码
char* intToRoman(int num) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    char* result = (char*)malloc(16 * sizeof(char)); // 罗马数字最长 15 字符
    result[0] = '\0';
    
    for (int i = 0; i < 13; ++i) {
        while (num >= values[i]) {
            strcat(result, symbols[i]);
            num -= values[i];
        }
    }
    return result;
}