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
} LNode;

// *pLb      类型是 LNode *，就是 Lb 的头指针
// **pLb     类型是 LNode，Lb 的头结点
Status MergeList(LNode *La,LNode **pLb)  //为什么是pLb而不是Lb？
{
    if(La == NULL || pLb == NULL || *pLb == NULL)
    {
        return ERROR;
    }

    //声明指针指向第一个数据结点
    LNode *pa = La->next;
    LNode *pb = (*pLb)->next;

    LNode *pc = La;     //pc 最初与 La 指向同一个头结点，之后 pc 会随着结点接入不断后移

    // 当 La、Lb 都还有待处理结点时，继续比较
    // 只要其中一条链表遍历完，就结束比较循环
    while(pa !=NULL && pb != NULL)
    {
        //如果 La 当前结点的数据小于或等于 Lb 当前结点的数据
        if(pa->data <= pb->data)
        {
            pc->next = pa;  // 让结果链表当前尾结点连接 pa 当前结点

            pc = pa; //把pc挪到pa，让pc指向pa

            pa = pa->next;      //pa往后挪一个结点
        }
        else    //a表的数据比b表的数据大的情况
        {
            pc->next = pb;  //下一位就接成pb这个结点

            pc = pb;        //pc往后挪到pb上

            pb = pb->next;      //如果是两个表，然后在a上修改，就是pb指针短暂的到了a表中，现在又回到了b表
        }
    }
    if(pa != NULL)  //La还有剩余部分
    {
        pc->next = pa;
    }
    else    //Lb还有剩余
    {
        pc->next = pb;
    }

    free(*pLb); //释放Lb的头指针

    *pLb = NULL;       //

    return OK;
}