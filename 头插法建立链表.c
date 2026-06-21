// 头插法建立单链表
// 每次把新结点插入到头结点之后，也就是当前链表的表头位置
// 有头结点时，头插的核心代码：
// s->next = L->next;
// L->next = s;

// 如果输入顺序是 a b c d e
// 使用头插法后，链表顺序会变成 e d c b a
// 所以头插法建立链表会得到输入序列的逆序

// 头插时只需要修改：
// 1. 新结点 s 的 next
// 2. 头结点 L 的 next
// 原来已有结点的 next 一般不需要修改
// 无头结点头插法
// 初始空表：L == NULL
// 创建新结点 s
// 让 s->next 指向原来的第一个结点，也就是 L
// 再让 L 指向 s
// 核心代码：
// s->next = L;
// L = s;

// 第一次插入时，因为 L == NULL，所以 s->next = NULL
// 之后每次插入，s->next 都指向原来的首元结点
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef int Status;     //为什么要有这个

#define OK 1
#define ERROR 0

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

Status InitList(LinkList *L)
{
    *L = (LNode *)malloc(sizeof(LNode));
    
    if(*L == NULL)
    {
        return ERROR;
    }

    (*L)->next = NULL;       //让头结点的 next 指向 NULL，表示空表

    return OK;
}

Status HeadInsert(LinkList L,ElemType e)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));

    if(s == NULL)
    {   // 申请新结点失败
        return ERROR;
    }
    
    s->data = e;    //让新节点的数据域被赋值数据e

    s->next = L->next;  //新节点指向下一结点
    L->next = s;    //上一结点指向新节点

    return OK;
}

void PrintList(LinkList L)
{
    LNode *p = L->next;

    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    LinkList L;

    if(InitList(&L) == ERROR)
    {
        printf("初始化失败\n");
        return 1;
    }

    HeadInsert(L,10);
    HeadInsert(L,20);
    HeadInsert(L,30);

    printf("链表内容：");
    PrintList(L);

    return 0;
}