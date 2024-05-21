#include <stdio.h>
#include "SqStack.h"    //**��03 ջ�Ͷ���**//

// ���Ժ�������ӡԪ��
void PrintElem(SElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    SqStack ss;
	LinkQueue lq;
	SqQueue sq;

    int i;
    SElemType e;
    
    printf("���������������� ˳��ջ���� InitStack \n");
    {
        printf("�� ��ʼ��˳��ջ ss ...\n");
        InitStack(&ss);
    }
    
    printf("���������������� ˳��ջ���� StackEmpty \n");
    {
        StackEmpty(ss) ? printf("�� ss Ϊ�գ���\n") : printf("�� ss ��Ϊ�գ�\n");
    }
    
    printf("���������������� ˳��ջ���� Push \n");
    {
        for(i = 1; i <= 6; i++) {
            Push(&ss, 2 * i);
            printf("�� �� \"%2d\" ѹ��ջ ss ...\n", 2 * i);
        }
    }
    
    printf("���������������� ˳��ջ���� StackTraverse \n");
    {
        printf("�� ss �е�Ԫ��Ϊ��ss = ");
        StackTraverse(ss, PrintElem);
    }
    
    printf("���������������� ˳��ջ���� StackLength \n");
    {
        i = StackLength(ss);
        printf("�� ss �ĳ���Ϊ %d \n", i);
    }
    
    printf("���������������� ˳��ջ���� Pop \n");
    {
        Pop(&ss, &e);
        printf("�� ջ��Ԫ�� \"%d\" ��ջ...\n", e);
        printf("�� ss �е�Ԫ��Ϊ��ss = ");
        StackTraverse(ss, PrintElem);
    }
    
    printf("���������������� ˳��ջ���� GetTop \n");
    {
        GetTop(ss, &e);
        printf("�� ջ��Ԫ�ص�ֵΪ \"%d\" \n", e);
    }
    
    printf("���������������� ˳��ջ���� ClearStack \n");
    {
        printf("�� ��� ss ǰ��");
        StackEmpty(ss) ? printf(" ss Ϊ�գ���\n") : printf(" ss ��Ϊ�գ�\n");
        
        ClearStack(&ss);
        
        printf("�� ��� ss ��");
        StackEmpty(ss) ? printf(" ss Ϊ�գ���\n") : printf(" ss ��Ϊ�գ�\n");
    }
    
    printf("���������������� ˳��ջ���� DestroyStack \n");
    {
        printf("�� ���� ss ǰ��");
        ss.base != NULL && ss.top != NULL ? printf(" ss ���ڣ�\n") : printf(" ss �����ڣ���\n");
        
        DestroyStack(&ss);
        
        printf("�� ���� ss ��");
        ss.base != NULL && ss.top != NULL ? printf(" ss ���ڣ�\n") : printf(" ss �����ڣ���\n");
    }
    
	//��������ADT�ĺ������Լ��в������ĺ�����Ҳ�������Ʒ������в���
    return 0;
}
