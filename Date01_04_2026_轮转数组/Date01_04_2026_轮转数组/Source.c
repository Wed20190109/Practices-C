#include <stdio.h>
/*
189. 轮转数组
中等

提示
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。



示例 1:

输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释:
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]


*/

//暴力求解法，时间复杂度O(n*k)
void rotate(int* nums, int numsSize, int k) {
	int k = k % numsSize;//可能会出现numssize=0的情况
    while (k--)
    {
        int tmp = nums[numsSize - 1];
        for (int i = numsSize - 1 - 1; i >= 0; i--)
        {
            nums[i + 1] = nums[i];
        }
        nums[0] = tmp;
    }
}

//三段反转

void reverse(int* nums, int left, int right)
{
    while (left < right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }

}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;//先取模，不然可能会越界访问
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);

}