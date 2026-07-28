void nextPermutation(int *nums, int numsSize) {
  int tmp = -1;

  // 先从右向左找，直到这个数大于前面的，存储下标
  for (int a = numsSize - 1; a > 0; a--) {
    if (nums[a] > nums[a - 1]) {
      tmp = a - 1;
      break;
    }
  }

  // 如果全部都小于，则为最大值，反转
  if (tmp == -1) {
    int right = 0;
    int left = numsSize - 1;
    while (right <= left) {
      int tmp1 = nums[right];
      nums[right] = nums[left];
      nums[left] = tmp1;
      right++;
      left--;
    }
    return;
  }

  // 寻找第一个比下标位置大的，然后交换
  for (int b = numsSize - 1; b > tmp; b--) {
    if (nums[b] > nums[tmp]) {
      int tmp2 = nums[b];
      nums[b] = nums[tmp];
      nums[tmp] = tmp2;

      break;
    }
  }

  // 交换完后，给下标之前的排为降序，变为交换后的最小
  for (int a = tmp + 1; a < numsSize - 1; a++) {
    for (int b = a + 1; b < numsSize; b++) {
      if (nums[a] > nums[b]) {
        int tmp3 = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp3;
      }
    }
  }
}