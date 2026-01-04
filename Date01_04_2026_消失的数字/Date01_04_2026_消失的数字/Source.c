#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
面试题 17.04. 消失的数字

简单

提示
数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？

注意：本题相对书上原题稍作改动

示例 1：

输入：[3,0,1]
输出：2


示例 2：

输入：[9,6,4,2,3,5,7,0,1]
输出：8
*/

//等差数列法:公式sum=n*(n+1)/2
//缺点:数组元素过大时会导致整数溢出
int missingNumber(int* nums, int numsSize) {

    //n*(n+1)/2
    int n = numsSize;
    int sum = n * (n + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        sum = sum - nums[i];
    }
    return sum;
}

//异或法
int missingNumber(int* nums, int numsSize)
{
    int N = numsSize;   // N 就是 n：理论上应该有 0..N 这 N+1 个数
    int x = 0;

    // ① 把数组里出现的所有数异或起来
    for (int i = 0; i < numsSize; ++i)
    {
        x ^= nums[i];
    }

    // ② 再把 0..N 全部异或起来
    for (int j = 0; j <= N; ++j)
    {
        x ^= j;
    }

    // ③ 返回结果
    return x;
}