#include <stdio.h>

/*
https://leetcode.cn/problems/partition-list-lcci/description/

给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你不需要 保留 每个分区中各节点的初始相对位置。



示例 1：


输入：head = [1,4,3,2,5,2], x = 3
输出：[1,2,2,4,3,5]
示例 2：

输入：head = [2,1], x = 2
输出：[1,2]


提示：

链表中节点的数目在范围 [0, 200] 内
-100 <= Node.val <= 100
-200 <= x <= 200
*/



  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
  struct ListNode* partition(struct ListNode* head, int x) {
      struct ListNode* smallhead = (struct ListNode*)malloc(sizeof(struct ListNode));
      struct ListNode* bighead = (struct ListNode*)malloc(sizeof(struct ListNode));
      struct ListNode* smalltail = smallhead;
      struct ListNode* bigtail = bighead;

      struct ListNode* cur = head;
      while (cur)
      {
          if (cur->val < x)
          {
              smalltail->next = cur;
              smalltail = smalltail->next;
          }
          else
          {
              bigtail->next = cur;
              bigtail = bigtail->next;
          }
          cur = cur->next;
      }
      bigtail->next = NULL;
      smalltail->next = bighead->next;
      struct ListNode* ret = smallhead->next;
      free(smallhead);
      free(bighead);
	  smallhead = bighead = NULL;
      return ret;
  }

  int main()
  {
      return 0;
  }