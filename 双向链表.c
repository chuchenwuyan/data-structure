// 单链表只能沿着 next 从前往后遍历
// 双向链表既可以沿 next 向后，也可以沿 prior 向前遍历
//结构：prior data next
// 非循环的带头结点双向链表中，头结点的 prior 为 NULL
// 头结点的 data 通常不存放有效数据

//还可以有双向循环链表
//双向循环链表的头结点的prior指向最后一个结点
//最后一个结点的next指向头结点
// 头结点的 next 指向第一个数据结点
// 第一个数据结点的 prior 指向头结点

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef int Status;

#define OK 1
#define ERROR 0

typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior,*next;
}DuLNode,*DuLinkList;

Status InitDuCircularList(DuLinkList *L)
{
    *L = (DuLNode *)malloc(sizeof(DuLNode));

    if(*L == NULL)
    {
        return ERROR;
    }

    (*L)->next = *L;
    (*L)->prior = *L;

    return OK;
}

// 双向链表插入：把 c 插入相邻结点 a 和 b 之间
// 原关系：a->next == b，b->prior == a
// 新关系：a ⇄ c ⇄ b

// 需要建立四条关系：
// c->prior = a
// c->next = b
// a->next = c
// b->prior = c

// 如果没有单独保存 b，就必须先利用 a->next 找到并处理 b，
// 最后才能把 a->next 改为 c

// 删除：
// 以 a、b、c 三个相邻结点为例，删除 b 结点
//
// 原结构：a ⇄ b ⇄ c
// 删除后：a ⇄ c
//
// 需要修改：
// a->next = c
// c->prior = a
//
// 若 p 指向要删除的 b：
p->prior->next = p->next;
p->next->prior = p->prior;
free(p);