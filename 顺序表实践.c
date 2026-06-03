#include <stdio.h>

#define MAXSIZE 100

teypedef struct
{
    int data[MAXSIZE];
    int length;
}SqList;

int main()
{
    Sqlist L;
    L.data[0] = 10;
    L.data[1] = 20;
    L.data[2] = 30;
    L.length = 3;

    for(int i = 0;i < L.length;i++)
    {
        printf("%d",L.data[i]);
    }
    return 0;
}