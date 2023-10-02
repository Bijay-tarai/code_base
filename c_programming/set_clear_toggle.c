#include<stdio.h>
int set(int num,int bit)
{
    int data;
    data=(num | (1 << (bit - 1)));
    return data;
}
int clear(int num,int bit)
{
    int data;
    data=(num & (~(1 << (bit - 1))));
    return data;
}
int toggle(int num,int bit)
{
    int data;
    data=(num ^ (1 << (bit - 1)));
    return data;
}
int main()
{
    int num,bit,data;

    printf("Enter number :");
    scanf("%d",&num);
    printf("Enter which bit to set/clear/toggle :");
    scanf("%d",&bit);

    data = set(num,bit);
    printf("after set %d bit data is %d\n",bit,data);
    data = clear(num,bit);
    printf("after clear %d bit data is %d\n",bit,data);
    data = toggle(num,bit);
    printf("after toggle %d bit data is %d\n",bit,data);
}