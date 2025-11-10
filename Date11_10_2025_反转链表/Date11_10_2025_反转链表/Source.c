#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
https://leetcode.cn/problems/reverse-linked-list/description/

给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。


示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例 2：
输入：head = [1,2]
输出：[2,1]

示例 3：
输入：head = []
输出：[]

*/
struct ListNode {
    int val;
    struct ListNode* next;  
};
struct ListNode* reverseList(struct ListNode* head) {

	/*
    请勿把这三个变量置于 if(head==NULL) 判断语句之前，因为不能确定head是否为空，且当head为空时，n2->next会引发异常
    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = n2->next;
    */
    if (head == NULL)
    {
        return head;
    }
    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = n2->next;
    while (n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3)
        {
            n3 = n3->next;
        }
    }
    return n1;
}