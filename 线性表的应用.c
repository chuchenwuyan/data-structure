// 线性表的合并：
// 求 La 和 Lb 的并集，结果保存到 La 中
// 依次取出 Lb 中的每个元素
// 判断该元素在 La 中是否存在
// 如果不存在，就插入 La 的表尾
// 如果已经存在，则不进行操作
// Lb 本身通常不改变
//时间复杂度是O(La_Length * Lb_Length)

#include <stdio.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

Status MergeList(List *La, const List *Lb)
{
    int La_len = ListLength(La);
    int Lb_len = ListLength(Lb);
    ElemType e;

    for (int i = 1; i <= Lb_len; i++)
    {
        // 取出 Lb 中第 i 个元素，保存到 e
        if (GetElem(Lb, i, &e) == ERROR)
        {
            return ERROR;
        }

        // 如果 La 中没有 e
        if (LocateElem(La, e) == 0)
        {
            // 把 e 插入 La 的表尾
            if (ListInsert(La, La_len + 1, e) == ERROR)
            {
                return ERROR;
            }

            La_len++;
        }
    }

    return OK;
}

//为什么称作非递增？因为有类似（8，8）这样相等的排列
//有序表的合并
//其时间复杂度是O(ListLength(La) + ListLength(Lb))
//空间复杂度是O(ListLength(La) + ListLength(Lb))

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
    int listSize;
}SqList;

Status MergeOrderedList(const SqList *La,const SqList *Lb,SqList *Lc)
{
    Lc->length = La->length + Lb->length;
    Lc->listsize = Lc->length;

    Lc->elem = malloc(sizeof(ElemType) * Lc->listSize);

    if(Lc->elem == NULL)
    {
        return ERROR;
    }
    ElemType *pa = La->elem;
    ElemType *pb = Lb->elem;

    ElemType *pc = Lc->elem;

    ElemType *pa_end = La->elem + La->length;
    ElemType *pb_end = Lb->elem + Lb->length;

    while(pa < pa_end && pb < pb_end)
    {
        if(*pa <= *pb)
        {
            *pc = *pa;

            pa++;
            pc++;
        }
        else
        {
            *pc = *pb;
            
            pb++;
            pc++;
        } 
    }

    while(pa < pa_end)
    {
        *pc = *pa;
        pa++;
        pc++;
    }
    while(pb < pb_end)
    {
        *pc = *pb;
        pb++;
        pc++;
    }

    return OK;
}

void PrintList(const SqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->elem[i]);
    }

    printf("\n");
}

int main()
{
    ElemType dataA[] = {1, 3, 5, 8};
    ElemType dataB[] = {2, 4, 6, 7};

    SqList La = {dataA,4,4};
    SqList Lb = {dataB,4,4};
    SqList Lc = {NULL,0,0};     //为什么这里是0，0？不应该是8，8吗

    if(MergeOrderedList(&La,&Lb,&Lc) == ERROR)
    {
        printf("合并失败");
        return 1;
    }

    printf("La:");
    printfList(&La);

    printf("Lb：");
    PrintList(&Lb);

    printf("合并后的 Lc：");
    PrintList(&Lc);
    
    free(Lc.elem);

    return 0;
}

//合并---用链表实现
//用La的头结点做Lc的头结点