#include <stdio.h>
#include "SqStack.h"    //**▲03 栈和队列**//

// 测试函数，打印元素
void PrintElem(SElemType e) {
    printf("%d ", e);
}


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
    
	//其他两个ADT的函数（自己有补充代码的函数）也按照类似方法进行测试
    return 0;
}
