// 头尾相接的链表
//最后一个结点的指针域指向头结点
// 遍历时，当当前结点指针再次等于头指针时结束
//如果是那种位置靠后的结点，那么从头结点往最后一个结点这样的方向会更方便吧
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef int Status;

#define OK 1
#define ERROR 0

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

Status LoopList(LinkList *L,int n)
{
    *L = (LNode *)malloc(sizeof(LNode));

    if(*L == NULL)
    {
        return ERROR;
    }

    (*L)->next = (*L);

    return OK;
}

//如何合并两条带有尾指针的循环链表？
// 将 A 的尾结点连接到 B 的第一个数据结点
// Tb 原本就是 B 的尾指针，合并后它也是整条链表的尾指针
// 合并后只保留 A 的头结点，因此释放 B 的头结点
//为什么要保存表头结点
LNode *Connect(LinkList *Ta,LinkList *Tb)
{
    LNode *headA = Ta->next;
    LNode *headB = Tb->next;

    Ta->next = headB->next;

    Tb->next = headA;

    free(headB);

    return Tb;
}