// 用顺序表表示多项式：
// 数组下标 i 表示 x 的指数 i
// elem[i] 保存 x^i 前面的系数
// 两个多项式相加时，将相同下标的系数相加

#include <stdio.h>

typedef int ElemType;
typedef int Status;

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef struct
{
    ELemType coef[MAXSIZE];
    int length;
}Polynomial;

Status CreatePolynomial(Polynomial *P, int length)
{
    if(length < 1 || length > MAXSIZE)
    {
        return ERROR;
    }

    p->length = length;
    printf("请依次输入 x^0 到 x^%d 的系数：\n", length - 1);

    for(int i = 0;i < length;i++)
    {
        scanf("%d",&p->coef[i]);
    }

    return OK;
}

//相加
Status AddPolynomial(const Polynomial *Pa,
    const Polynomial *Pb,
    Polynomial *Pc)
    {
        if(Pa->length >= PB->length)
        {
            Pc->length = Pa->length;
        }
        else
        {
            Pc->length = Pb->length;
        }

        for(int i = 0;i < Pc->length;i++)
        {
            ElemType a = 0,b = 0;

            if(i < Pa->length)  //取出多项式当前项的系数
            {
                a = Pa->coef[i]; 
            }
            if(i < Pb->length)
            {
                b = Pb->coef[i];
            }
            Pc->coef[i] = a + b;
        }

        while(Pc->length > 1 &&
        Pc->coef[Pc->length - 1] == 0)
        {
            Pc->length--;
        }

        return OK;
    }
int main()
{}