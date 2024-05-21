#include <stdio.h>
#include "SqStack.h"    //**▲03 栈和队列**//
#include "LinkQueue.h"
#include "SqQueue.h"

// 测试函数，打印元素
void PrintElem(SElemType e) {
    printf("%d ", e);
}
/*
void testLinkQueue() {
    printf("\nTesting LinkQueue...\n");
    LinkQueue lq;
    LinkInitQueue(&lq);
    printf("Queue initialized.\n");

    printf("Enqueue elements 1, 2, 3...\n");
    for(QElemType i = 1; i <= 3; i++) {
        LinkEnQueue(&lq, i);
    }

    QElemType elem;
    LinkGetHead(lq, &elem);
    printf("The head of the queue: %d\n", elem);

    printf("Queue Length: %d\n", LinkQueueLength(lq));

    printf("Dequeue elements...\n");
    while(!LinkQueueEmpty(lq)) {
        LinkDeQueue(&lq, &elem);
        printf("%d dequeued\n", elem);
    }

    // Assuming there's a LinkClearQueue to clear the queue.
    LinkClearQueue(&lq);
    printf("Queue cleared. Is empty: %s\n", LinkQueueEmpty(lq) ? "Yes" : "No");

    // If there's a LinkDestroyQueue, it would go here.
}

void testSqQueue() {
    printf("\nTesting SqQueue...\n");
    SqQueue sq;
    SqInitQueue(&sq);
    printf("Queue initialized.\n");

    printf("Enqueue elements 4, 5, 6...\n");
    for(QElemType i = 4; i <= 6; i++) {
        SqEnQueue(&sq, i);
    }

    QElemType elem;
    SqGetHead(sq, &elem);
    printf("The head of the queue: %d\n", elem);

    printf("Queue Length: %d\n", SqQueueLength(sq));

    printf("Dequeue elements...\n");
    while(!SqQueueEmpty(sq)) {
        SqDeQueue(&sq, &elem);
        printf("%d dequeued\n", elem);
    }

    // Assuming there's a SqClearQueue to clear the queue.
    SqClearQueue(&sq);
    printf("Queue cleared. Is empty: %s\n", SqQueueEmpty(sq) ? "Yes" : "No");

    // If there's a SqDestroyQueue, it would go here.
}
*/
int main(int argc, char** argv) {
    SqStack ss;
	LinkQueue lq;
	SqQueue sq;

    int i;
    SElemType e;
    
    printf("████████ 顺序栈函数 InitStack \n");
    {
        printf("█ 初始化顺序栈 ss ...\n");
        InitStack(&ss);
    }
    
    printf("████████ 顺序栈函数 StackEmpty \n");
    {
        StackEmpty(ss) ? printf("█ ss 为空！！\n") : printf("█ ss 不为空！\n");
    }
    
    printf("████████ 顺序栈函数 Push \n");
    {
        for(i = 1; i <= 6; i++) {
            Push(&ss, 2 * i);
            printf("█ 将 \"%2d\" 压入栈 ss ...\n", 2 * i);
        }
    }
    
    printf("████████ 顺序栈函数 StackTraverse \n");
    {
        printf("█ ss 中的元素为：ss = ");
        StackTraverse(ss, PrintElem);
    }
    
    printf("████████ 顺序栈函数 StackLength \n");
    {
        i = StackLength(ss);
        printf("█ ss 的长度为 %d \n", i);
    }
    
    printf("████████ 顺序栈函数 Pop \n");
    {
        Pop(&ss, &e);
        printf("█ 栈顶元素 \"%d\" 出栈...\n", e);
        printf("█ ss 中的元素为：ss = ");
        StackTraverse(ss, PrintElem);
    }
    
    printf("████████ 顺序栈函数 GetTop \n");
    {
        GetTop(ss, &e);
        printf("█ 栈顶元素的值为 \"%d\" \n", e);
    }
    
    printf("████████ 顺序栈函数 ClearStack \n");
    {
        printf("█ 清空 ss 前：");
        StackEmpty(ss) ? printf(" ss 为空！！\n") : printf(" ss 不为空！\n");
        
        ClearStack(&ss);
        
        printf("█ 清空 ss 后：");
        StackEmpty(ss) ? printf(" ss 为空！！\n") : printf(" ss 不为空！\n");
    }
    
    printf("████████ 顺序栈函数 DestroyStack \n");
    {
        printf("█ 销毁 ss 前：");
        ss.base != NULL && ss.top != NULL ? printf(" ss 存在！\n") : printf(" ss 不存在！！\n");
        
        DestroyStack(&ss);
        
        printf("█ 销毁 ss 后：");
        ss.base != NULL && ss.top != NULL ? printf(" ss 存在！\n") : printf(" ss 不存在！！\n");
    }
    
    printf("████████ 链队列函数 LinkInitQueue \n");
    {
        LinkQueue lq;
        printf("█ 初始化链队列 lq ...\n");
        LinkInitQueue(&lq);
    }

    printf("████████ 链队列函数 LinkQueueEmpty \n");
    {
        LinkQueueEmpty(lq) ? printf("█ lq 为空！！\n") : printf("█ lq 不为空！\n");
    }

    printf("████████ 链队列函数 LinkEnQueue \n");
    {
        for(i = 1; i <= 6; i++) {
            LinkEnQueue(&lq, 2 * i);
            printf("█ 将 \"%2d\" 入队到 lq ...\n", 2 * i);
        }
    }

    printf("████████ 链队列函数 LinkQueueLength \n");
    {
        i = LinkQueueLength(lq);
        printf("█ lq 的长度为 %d \n", i);
    }

    printf("████████ 链队列函数 LinkDeQueue \n");
    {
        QElemType e;
        LinkDeQueue(&lq, &e);
        printf("█ 队首元素 \"%d\" 出队...\n", e);
    }

    printf("████████ 链队列函数 LinkGetHead \n");
    {
        LinkGetHead(lq, &e);
        printf("█ 队首元素的值为 \"%d\" \n", e);
    }

        printf("████████ 顺序队列函数 SqInitQueue \n");
    {
        SqQueue sq;
        printf("█ 初始化顺序队列 sq ...\n");
        SqInitQueue(&sq);
    }

    printf("████████ 顺序队列函数 SqQueueEmpty \n");
    {
        SqQueueEmpty(sq) ? printf("█ sq 为空！！\n") : printf("█ sq 不为空！\n");
    }

    printf("████████ 顺序队列函数 SqEnQueue \n");
    {
        for(i = 1; i <= 6; i++) {
            SqEnQueue(&sq, 2 * i);
            printf("█ 将 \"%2d\" 入队到 sq ...\n", 2 * i);
        }
    }

    printf("████████ 顺序队列函数 SqQueueLength \n");
    {
        i = SqQueueLength(sq);
        printf("█ sq 的长度为 %d \n", i);
    }

    printf("████████ 顺序队列函数 SqDeQueue \n");
    {
        QElemType e;
        SqDeQueue(&sq, &e);
        printf("█ 队首元素 \"%d\" 出队...\n", e);
    }

    printf("████████ 顺序队列函数 SqGetHead \n");
    {
        SqGetHead(sq, &e);
        printf("█ 队首元素的值为 \"%d\" \n", e);
    }

    printf("████████ 顺序队列函数 SqClearQueue \n");
    {
        printf("█ 清空 sq 前：");
        SqQueueEmpty(sq) ? printf(" sq 为空！！\n") : printf(" sq 不为空！\n");
        
        SqClearQueue(&sq);
        
        printf("█ 清空 sq 后：");
        SqQueueEmpty(sq) ? printf(" sq 为空！！\n") : printf(" sq 不为空！\n");
    }
	//其他两个ADT的函数（自己有补充代码的函数）也按照类似方法进行测试
    // testLinkQueue();
    // testSqQueue();
    return 0;
}
