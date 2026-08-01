// 线性表A = ((7, 0), (3, 1), (9, 8), (5, 17))
// 线性表B = ((8, 1), (22, 7), (-9, 8))
//创建一个新数组c

// 分别从头遍历比较 a 和 b 的每一项
// 指数相同，对应系数相加，若其和不为零，则在 c 中增加一个新项
// 指数不相同，则将指数较小的项复制到 c 中

//当一个多项式已经遍历完毕，那么另一个多项式的项依次复制进c即可

//数组c的大小多大合适？我认为最稳妥的是A+B的大小

// 顺序存储需要预先确定或扩充容量，插入时可能需要移动元素。
// 如果按指数直接作为数组下标，指数跨度很大时会浪费空间。
// 链式存储可以按实际非零项动态申请结点，但每个结点还需要额外保存 next 指针。

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef struct Node
{
    int coef;
    int expn;
    struct Node *next;
}Node;


//创建多项式
// 创建多项式，要求输入项已按指数非递减排列，且表内无重复指数
int Create(Node **P,int n)
{
    *P = malloc(sizeof(Node));

    if(*P == NULL)
    {
        return ERROR;
    }

    (*P)->next = NULL;  //让头结点指向空


    Node *tail = *P;

    for(int i = 0;i < n;i++)
    {
        Node *s = malloc(sizeof(Node)); //声明指针s，并申请一个新结点，让s指向它

        if(s == NULL)   //申请失败
        {
            return ERROR;
        }

        printf("输入第%d项的系数和指数：",i + 1);
        scanf("%d%d",&s->coef,&s->expn);
        
        s->next = NULL;     //新结点目前没有后继，接入链表后将成为当前尾结点

        tail->next = s; //当前尾结点连接新结点
        tail = s;   // 新结点成为新的尾结点
    }

    return OK;
}

int Add(Node *A,Node *B,Node **C)   //为什么这里的C表是**而不是*
{
    *C = malloc(sizeof(Node));

    if(*C == NULL)
    {
        return ERROR;
    }

    (*C)->next = NULL;  //结果链表目前只有头结点，没有数据结点

    Node *pa = A->next; //用指针变量pa保存A的待处理结点的地址
    Node *pb = B->next; //用指针变量pb保存B的待处理结点的地址
    Node *tail = *C;    //tail初始指向C的头结点

    while(pa != NULL && pb != NULL)
    {
        int coef;
        int expn;

        if(pa->expn < pb->expn) //如果指数比b小
        {
            coef = pa->coef;    //此结点的系数和项数就使用a的数据
            expn = pa->expn;

            pa = pa->next;  //向下一节点挪动
        }
        else if(pa->expn > pb->expn)    //项数比b大
        {
            coef = pb->coef;
            expn = pb->expn;
            
            pb = pb->next;
        }
        else    //项数相等
        {
            coef = pa->coef + pb->coef;
            expn = pa->expn;
            //两指针变量都指向下一结点
            pa = pa->next;
            pb = pb->next;

            if(coef == 0)   //两项的系数相加等于0，比如说-7+7
            {
                continue;
            }
        }
        //已经确定结果中的系数和指数，现在申请一个新结点保存它们
        Node *s = malloc(sizeof(Node));

        if(s == NULL)
        {
            return ERROR;
        }

        s->coef = coef;
        s->expn = expn;
        s->next = NULL;
        //把tail挪到s上
        tail->next = s;
        tail = s;
    }
    while(pa != NULL)   //如果b先复制完
    {
        Node *s = malloc(sizeof(Node));

        if(s == NULL)
        {
            return ERROR;
        }

        s->coef = pa->coef;
        s->expn = pa->expn;
        s->next = NULL; //因为是一个结点一个结点复制的，所以每次把a当前处理的结点复制进c是，s结点都是最后一个结点，所以s->next一定指向NULL

        tail->next = s;
        tail = s;

        pa = pa->next;
    }
    //b同理
    while(pb != NULL)
    {
        Node *s = malloc(sizeof(Node));

        if(s == NULL)
        {
            return ERROR;
        }

        s->coef = pb->coef;
        s->expn = pb->expn;
        s->next = NULL;

        tail->next = s;
        tail = s;

        pb = pb->next;
    }
    return OK;
}
//核心逻辑已经完成

void Print(Node *P)
{
    Node *p = P->next;

    while (p != NULL)
    {
        printf("(%d,%d)", p->coef, p->expn);

        if (p->next != NULL)
        {
            printf(" -> ");
        }

        p = p->next;
    }

    printf("\n");
}


/* 销毁链表 */
void FreeList(Node **P)
{
    Node *p = *P;

    while (p != NULL)
    {
        Node *next = p->next;

        free(p);
        p = next;
    }

    *P = NULL;
}

int main()
{
    Node *A = NULL;
    Node *B = NULL;
    Node *C = NULL;

    int nA;
    int nB;

    printf("输入A的项数：");
    scanf("%d",&nA);

    printf("输入B的项数：");
    scanf("%d",&nB);

    Create(&A,nA);
    Create(&B,nB);

    Add(A,B,&C);

    printf("\nA：");
    Print(A);

    printf("B：");
    Print(B);

    printf("C：");
    Print(C);

    FreeList(&A);
    FreeList(&B);
    FreeList(&C);

    return 0;
}