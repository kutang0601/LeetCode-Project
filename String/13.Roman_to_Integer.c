#include <stdio.h>

int romanToInt(char* s) {
    int arr[27][3] = {0};
    arr['I' - 'A'][0] = 1;
    arr['V' - 'A'][0] = 5;
    arr['X' - 'A'][0] = 10;
    arr['L' - 'A'][0] = 50;
    arr['C' - 'A'][0] = 100;
    arr['D' - 'A'][0] = 500;
    arr['M' - 'A'][0] = 1000;

    while (*s)
    {
        if (*(s + 1) && (*(s + 1) == 'V' || *(s + 1) == 'X') && *s == 'I')
        {
            arr[*s - 'A'][2]++;
        }
        else if (*(s + 1) && (*(s + 1) == 'L' || *(s + 1) == 'C') && *s == 'X')
        {
            arr[*s - 'A'][2]++;
        }
        else if (*(s + 1) && (*(s + 1) == 'D' || *(s + 1) == 'M') && *s == 'C')
        {
            arr[*s - 'A'][2]++;
        }
        else
        {
            arr[*s - 'A'][1]++;
        }

        s++;
    }

    long long ret = 0;
    int arr1[7] = {'I' - 'A', 'V' - 'A', 'X' - 'A', 'L' - 'A', 'C' - 'A', 'D' - 'A', 'M' - 'A'};
    for (int n = 0; n < 7; n++)
    {
        ret += (arr[arr1[n]][1] - arr[arr1[n]][2]) * arr[arr1[n]][0];
    }

    return ret;
}