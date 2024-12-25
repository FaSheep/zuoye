/*=========================
 * 队列的链式存储结构（链队）
 ==========================*/


#include <stdio.h>
#include <stdlib.h>     
#include "Common.h"   

/* 链队元素类型定义 */
typedef int QElemType;

// 队列元素结构
typedef struct QNode {
    QElemType data;
    struct QNode* next;
} QNode, * QueuePtr;

// 队列结构
typedef struct {
    QueuePtr front;
    QueuePtr rear;      // 队尾指针
} LinkQueue;            // 队列的链式存储表示


Status LinkInitQueue(LinkQueue* Q);
Status LinkDestroyQueue(LinkQueue* Q);
Status LinkClearQueue(LinkQueue* Q);
Status LinkQueueEmpty(LinkQueue Q);
int LinkQueueLength(LinkQueue Q);
Status LinkGetHead(LinkQueue Q, QElemType* e);
Status LinkEnQueue(LinkQueue* Q, QElemType e);
Status LinkDeQueue(LinkQueue* Q, QElemType* e);
Status LinkQueueTraverse(LinkQueue Q, void(Visit)(QElemType));
