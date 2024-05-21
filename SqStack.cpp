/*=========================
 * ջ��˳��洢�ṹ��˳��ջ��
 ==========================*/

#include "SqStack.h"    //**��03 ջ�Ͷ���**//

/*
 * ��ʼ��
 *
 * ����һ����ջ����ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 */
Status InitStack(SqStack* S) {
    if(S == NULL) {
        return ERROR;
    }
    
    //�������    
    return OK;
}

/*
 * ����(�ṹ)
 *
 * �ͷ�˳��ջ��ռ�ڴ档
 */
Status DestroyStack(SqStack* S) {
    if(S == NULL) {
        return ERROR;
    }
    
    free((*S).base);
    
    (*S).base = NULL;
    (*S).top = NULL;
    (*S).stacksize = 0;
    
    return OK;
}

/*
 * �ÿ�(����)
 *
 * ֻ������˳��ջ�д洢�����ݣ����ͷ�˳��ջ��ռ�ڴ档
 */
Status ClearStack(SqStack* S) {
    if(S == NULL || (*S).base == NULL) {
        return ERROR;
    }
    
    (*S).top = (*S).base;
    
    return OK;
}

/*
 * �п�
 *
 * �ж�˳��ջ���Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ˳��ջΪ��
 * FALSE: ˳��ջ��Ϊ��
 */
Status StackEmpty(SqStack S) {
    if(S.top == S.base) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*
 * ����
 *
 * ����˳��ջ��������ЧԪ�ص�������
 */
int StackLength(SqStack S) {
    if(S.base == NULL) {
        return 0;
    }
    
    //�������
}

/*
 * ȡֵ
 *
 * ����ջ��Ԫ�أ�����e���ա�
 */
Status GetTop(SqStack S, SElemType* e) {
    if(S.base == NULL || S.top == S.base) {
        return 0;
    }
    
    // ����ı�ջ��Ԫ��
     //�������
    
    return OK;
}

/*
 * ��ջ
 *
 * ��Ԫ��eѹ�뵽ջ����
 */
Status Push(SqStack* S, SElemType e) {
    if(S == NULL || (*S).base == NULL) {
        return ERROR;
    }
    
    // ջ��ʱ��׷�Ӵ洢�ռ�
    if((*S).top - (*S).base >= (*S).stacksize) {
        (*S).base = (SElemType*) realloc((*S).base, ((*S).stacksize + STACKINCREMENT) * sizeof(SElemType));
        if((*S).base == NULL) {
            exit(OVERFLOW);     // �洢����ʧ��
        }
        
        (*S).top = (*S).base + (*S).stacksize;
        (*S).stacksize += STACKINCREMENT;
    }
    
    // ��ջ�ȸ�ֵ��ջ��ָ��������
     //�������
    
    return OK;
}

/*
 * ��ջ
 *
 * ��ջ��Ԫ�ص���������e���ա�
 */
Status Pop(SqStack* S, SElemType* e) {
    if(S == NULL || (*S).base == NULL) {
        return ERROR;
    }
    
    if((*S).top == (*S).base) {
        return ERROR;
    }
    
    // ��ջջ��ָ���ȵݼ����ٸ�ֵ
     //�������
    
    return OK;
}

/*
 * ����
 *
 * ��visit��������˳��ջS
 */
Status StackTraverse(SqStack S, void(Visit)(SElemType)) {
	SElemType* p = S.base;

    if(S.base == NULL) {
        return ERROR;
    }

    while(p < S.top) {
        Visit(*p++);
    }
    
    printf("\n");
    
    return OK;
}