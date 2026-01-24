#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS 1
/*
描述
对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。

给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。

测试样例：
1->2->2->1
返回：true
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        struct ListNode* mid = middleNode(A);
        struct ListNode* rmid = reverseList(mid);
        while (rmid && A)
        {
            if (rmid->val != A->val)
                return false;
            rmid = rmid->next;
            A = A->next;
        }
        return true;
    }

    //查找中间节点函数
    struct ListNode* middleNode(struct ListNode* head)
    {
        struct ListNode* slow = head;
        struct ListNode* fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    //反转链表函数
    struct ListNode* reverseList(struct ListNode* head)
    {
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
    };
};