#include <stdio.h>

double calculateTax(int** brackets, int bracketsSize, int* bracketsColSize, int income) {
    double takes = 0.0;
    for (int i = 0; i < bracketsSize; i++)
    {
        if (income >= brackets[i][0])
        {
            if (i == 0)
                takes += brackets[i][0] * 1.0 * (brackets[i][1] * 1.0 / 100);
            else
                takes += (brackets[i][0] - brackets[i - 1][0]) * 1.0 * (brackets[i][1] * 1.0 / 100);
        }
        else
        {
            if (i == 0)
                takes += income * 1.0 * (brackets[i][1] * 1.0 / 100);
            else
                takes += (income - brackets[i - 1][0]) * 1.0 * (brackets[i][1] * 1.0 / 100);
            break;
        }
    }

     return takes;
}