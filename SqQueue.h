/*=============================
 * 队列的顺序存储结构（顺序队列）
 ==============================*/

#include <stdio.h>
#include <stdlib.h>       
#include "Common.h" 

/* 宏定义 */
#define MAXQSIZE 1000   //最大队列长度

/* 循环队列元素类型定义 */
typedef int QElemType;

// 循环队列的顺序存储结构
typedef struct {
    QElemType* base;    // 动态分配存储空间
    int front;          // 头指针，若队列不空，指向队头元素
    int rear;           // 尾指针，若队列不空，指向队列尾元素的下一个位置
} SqQueue;


Status SqInitQueue(SqQueue* Q);
Status SqDestroyQueue(SqQueue* Q);
Status SqClearQueue(SqQueue* Q);
Status SqQueueEmpty(SqQueue Q);
int SqQueueLength(SqQueue Q);
Status SqGetHead(SqQueue Q, QElemType* e);
Status SqEnQueue(SqQueue* Q, QElemType e);
Status SqDeQueue(SqQueue* Q, QElemType* e);
Status SqQueueTraverse(SqQueue Q, void(Visit)(QElemType));