include <stdio.h>


int closestTarget(char** words, int wordsSize, char* target, int startIndex) 
{
    int n = wordsSize;
    int x = 0;
    while (n--)
    {
        if (!strcmp(words[n], target))
        {
            x++;
        }
    }
    if (!x)
        return -1;

    int arr[100] = {0};
    int o = 0;
    int len = 0;
    int front = wordsSize;
    int back = wordsSize;

    while(front--)
    {
        if (!strcmp(words[(startIndex + len) % wordsSize], target))
        {
            arr[o] = len;
            o++;
        }
        len++;
    }

    len = 0;

    while(back--)
    {
        if (!strcmp(words[(startIndex - len + wordsSize) % wordsSize], target))
        {
            arr[o] = len;
            o++;
        }
        len++;
    }

    int min = -1;

    for (int s = 0; s < o; s++)
    {
        if (min == -1)
            min = arr[s];
        if(min > arr[s])
            min = arr[s];
    }

    return min;
}
    

int main()
{
    
    return 0;   
}