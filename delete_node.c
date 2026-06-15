//删除结点
// 那我直接把上一个结点的指针域指向下一个结点不就行了，这样中间的结点就丢失了
//有需要就保存，不需要就无所谓
#include <stdlib.h>
#include <stdio.h>


typedef int ElemType;
typedef int Status;

#define OK 1
#define ERROR 0

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

Status ListDelete_L(LinkList L, int i, ElemType *e)
{
    LNode *p = L;
    LNode *q;
    int j = 0;

    if (i < 1)
    {
        return ERROR;
    }

    while(p->next != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if(p->next == NULL)
    {
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);

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
{   //创建列表
    LinkList L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    //创建a,b,c三个结点
    LNode *a = (LNode *)malloc(sizeof(LNode));
    LNode *b = (LNode *)malloc(sizeof(LNode));
    LNode *c = (LNode *)malloc(sizeof(LNode));
    //给三个结点赋值
    a->data = 10;
    b->data = 20;
    c->data = 30;
    //指针域各自指向下一个结点
    L->next = a;
    a->next = b;
    b->next = c;
    c->next = NULL;
    printf("删除前：");
    PrintList(L);

    ElemType e;

    if(ListDelete_L(L,2,&e) == OK)
    {
        printf("删除成功，被删除的元素是：%d\n", e);
    }
    else
    {
        printf("删除失败\n");
    }

    printf("删除后：");
    PrintList(L);
    return 0;
}