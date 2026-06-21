//一开始头指针L和尾指针r都指向头结点。
//在末尾插入一个新结点s，置空他的指针域，让r指向s
// 头结点的指针域也就是(*L)->next = s
//之后就大概是循环这个流程
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef int Status;

#define OK 1
#define ERROR 0

typedef struct LNod
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

Status CreateList_Tail(LinkList *L,int n)
{
    *L = (LNode *)malloc(sizeof(LNode));

    if(*L == NULL)
    {
        return ERROR;
    }

    (*L)->next = NULL:

    LNode *r = *L;

    for(int i = 0;i < n;i++)
    {
        ElemType e;

        printf("请输入第%d个元素：", i + 1);
        scanf("%d",&e);

        LNode *s = (LNode *)malloc(sizeof(LNode));

        if(s == NULL)
        {
            return ERROR;
        }

        s->data = e;
        s->next = NULL;

        r->next = s;
        r = s
    }
    return OK;
}

void PrintList(LinkList L)
{
    // 从首元结点开始
    LNode *p = L->next;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

void PrintList(LinkList L)
{
    // 从首元结点开始
    LNode *p = L->next;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

int main()
{
    LinkList L;
    int n;

    printf("请输入元素个数：");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("元素个数不合法\n");
        return 1;
    }

    if (CreateList_Tail(&L, n) == ERROR)
    {
        printf("链表创建失败\n");
        return 1;
    }

    printf("链表内容：");
    PrintList(L);

    DestroyList(&L);

    return 0;
}