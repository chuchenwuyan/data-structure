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
    //创建一个空链表
    *L = (LNode *)malloc(sizeof(LNode));
    
    if(*L == NULL)
    {
        return ERROR;
    }

    (*L)->next = NULL;

    LNode *r = *L;      //r 和头指针暂时都指向同一个头结点。

    for(int i = 0;i < n;i++)
    {
        //创建新结点
        LNode *s = (LNode *)malloc(sizeof(LNode));
        //检查
        if(s == NULL)
        {
            return ERROR;
        }
        //赋值
        printf("输入：");
        scanf("%d",&s->data);

        s->next = NULL;

        r->next = s;

        r = s;  //让尾指针移到新节点
    }
    return OK;
}