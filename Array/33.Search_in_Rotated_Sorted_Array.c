int search(int* nums, int numsSize, int target) 
{
    int left = 0;
    int rightt = numsSize - 1;

    while (left <= rightt)
    {
        int mid = left + (rightt - left) / 2;

        if(nums[mid] == target)
            return mid;

        if (nums[mid] >= nums[left])
        {
            if (nums[mid] > target && target >= nums[left])
                rightt = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (nums[mid] < target && nums[rightt] >= target)
                left = mid + 1;
            else
                rightt = mid - 1;
        }
    }

    return -1;

}