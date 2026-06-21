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

Status CreatList_Tail(LinkList *L,int n)
{
    *L = malloc(sizeof(LNode));

    if(*L == NULL)
    {
        return ERROR;
    }

    (* L)->next = NULL;

    LNode *r = *L;

    for(int i = 0;i < n;i++)
    {
        Lnode *s = (LNode *)malloc(sizeof(LNode));

        if(s == NULL)
        {
            return ERROR;
        }
        //输入数据
        printf("请输入第%d个元素：", i + 1);
        scanf("%d", &s->data);

        s->next = NULL;

        r->next = s;

        r = s;
    }

    return OK;
}

