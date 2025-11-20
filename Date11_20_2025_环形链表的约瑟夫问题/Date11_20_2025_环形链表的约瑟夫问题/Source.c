#include <stdio.h>

/*
https://www.nowcoder.com/practice/41c399fdb6004b31a6cbb047c641ed8a

编号为 1 到 n 的 n 个人围成一圈。从编号为 1 的人开始报数，报到 m 的人离开。
下一个人继续从 1 开始报数。
n-1 轮结束以后，只剩下一个人，问最后留下的这个人编号是多少？
数据范围：1≤n,m≤10000
进阶：空间复杂度O(1)，时间复杂度O(n)

示例1
输入：
5,2

返回值：
3

说明：
开始5个人 1，2，3，4，5 ，从1开始报数，1->1，2->2编号为2的人离开
1，3，4，5，从3开始报数，3->1，4->2编号为4的人离开
1，3，5，从5开始报数，5->1，1->2编号为1的人离开
3，5，从3开始报数，3->1，5->2编号为5的人离开
最后留下人的编号是3
示例2
输入：
1,1

返回值：
1

*/

typedef struct Node {
    int val;
    struct Node* next;
}node;

node* createnode(int x)
{
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL)
    {
        perror("malloc");
        exit(0);
    }
    newnode->val = x;
    newnode->next = NULL;
    return newnode;
}

node* createcircle(int n)
{
    node* head = createnode(1);
    node* tail = head;
    for (int i = 2; i <= n; i++)
    {
        tail->next = createnode(i);
        tail = tail->next;
    }
    tail->next = head;
    return tail;
}

int ysf(int n, int m) {
    // write code here


    node* prev = createcircle(n);
    node* cur = prev->next;
    int count = 1;
    while (cur->next != cur)
    {
        if (count == m)
        {
            prev->next = cur->next;
            free(cur);
            cur = prev->next;
            count = 1;
        }
        else
        {
            prev = cur;
            cur = cur->next;
            count++;
        }
    }
    return cur->val;
}

int main()
{
    return 0;
}