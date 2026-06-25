//双指针解法
bool isPalindrome(int x) {
    if (x < 0)
        return false;
    char* ch = (char*)malloc(sizeof(char) * 32);
    char* tail = ch; 
    while (x)
    {
        *tail = x % 10;
        x /= 10;
        tail++;
    }
    tail--;
    while (tail >= ch)
    {
        if (*tail != *ch)
            return false;
        tail--;
        ch++;
    }

    return true;
}