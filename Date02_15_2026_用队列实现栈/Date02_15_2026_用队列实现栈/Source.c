#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/*https://leetcode.cn/problems/implement-stack-using-queues/description/
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：

void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。


注意：

你只能使用队列的标准操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。


示例：

输入：
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 2, 2, false]

解释：
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False


提示：

1 <= x <= 9
最多调用100 次 push、pop、top 和 empty
每次调用 pop 和 top 都保证栈不为空


进阶：你能否仅用一个队列来实现栈。
*/
/*

思路：用两个队列来实现栈，push操作时，把元素压入暂存队列q2，然后把q1的元素逐渐挪动到q2，最后交换q1和q2的指针，这样就保证了
q1的队头永远是栈顶元素了，pop和top操作直接从q1的队头进行即可

主队列为q1，暂存队列为q2
*/

typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* front;//队头
	QNode* rear;//队尾
	int size;
}Queue;

void QueueInit(Queue* pq) {
	assert(pq);
	pq->front = NULL;
	pq->rear = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->data = x;
	newnode->next = NULL;
	if (pq->rear == NULL)
	{
		pq->front = pq->rear = newnode;
	}
	else
	{
		pq->rear->next = newnode;
		pq->rear = newnode;
	}
	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->front);
	QNode* newnode = pq->front->next;//只能头节点被删除，所以直接把头节点的下一个节点保存起来，最后把头节点free掉就行了
	free(pq->front);
	pq->front = newnode;
	if (pq->front == NULL)//也可以在开头判断是不是只有一个节点，如果是一个节点，直接free掉就行了
	{
		pq->rear = NULL;
	}
	pq->size--;
}

QDataType GetQueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->front);
	return pq->front->data;
}

QDataType GetQueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->rear);
	return pq->rear->data;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->front = pq->rear = NULL;
	pq->size = 0;
}

void QueuePrint(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->front;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}



typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&(pst->q1));
	QueueInit(&(pst->q2));
	return pst;
}

void myStackPush(MyStack* obj, int x) {
	QueuePush(&(obj->q2), x);
	while (!QueueEmpty(&(obj->q1)))//逐渐挪动q1的元素到暂存队列q2，逐渐排空
	{
		int temp = GetQueueFront(&obj->q1);
		QueuePop(&obj->q1);
		QueuePush(&obj->q2, temp);
	}
	Queue tmp = obj->q1;
	obj->q1 = obj->q2;
	obj->q2 = tmp;
}

int myStackPop(MyStack* obj) {
	int ret = GetQueueFront(&obj->q1);
	QueuePop(&obj->q1);
	return ret;

}

int myStackTop(MyStack* obj) {
	return GetQueueFront(&obj->q1);
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/