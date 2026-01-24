#include <stdio.h>
/*
面试题 02.02. 返回倒数第 k 个节点

提示
实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

注意：本题相对原题稍作改动

示例：

输入： 1->2->3->4->5 和 k = 2
输出： 4
说明：

给定的 k 保证是有效的。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int kthToLast(struct ListNode* head, int k) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (k--)
    {
        fast = fast->next;
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->val;
}