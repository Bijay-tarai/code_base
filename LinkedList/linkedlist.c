#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node* root=NULL;

void append();
int length();
void display();
//void addatbegin();
void delete();
void reverse();


int len;
void main()
{
    int ch;
    while(1)
    {
        printf("****************SINGLE LINKEDLIST OPERATION*****************\n");

        printf("1.Append\n");
        printf("2.Addatbegin\n");
        printf("3.AddatAfter\n");
        printf("4.Length\n");
        printf("5.Display\n");
        printf("6.Delete\n");
        printf("7.Reverse\n");
        printf("8.Quit\n");

        printf("Enter your choice :");
        scanf("%d",&ch);

        switch ((ch))
        {
        case 1:
            append();
            break;
        case 2:
        //   addatbegin();
            break;
        case 3:
        //   addatafter();
            break;
        case 4:
            len = length();
            printf("Length : %d\n\n",len);
            break;
        case 5:
            display();
            break;
        case 6:
            delete();
            break;
        case 7:
            reverse();
            break;
        case 8:
            exit(0);
            break;
        
        default:
            printf("Invalid Input\n");
            break;
        }

    }
}

void append()
{
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter node data\n");
    scanf("%d",&temp->data);

    temp->link = NULL;

    if(root == NULL)/*check 1st if root is null or not*/
    {
        root = temp;
    }
    else{
        struct Node* p;
        p=root;
        while(p->link != NULL)//is another node is available or not
        {
            p=p->link;
        }
        p->link = temp;
    }
    
}
int length()
{
    int count = 0;
    struct Node* temp;
    temp=root;
    while(temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;

}
void display()
{
    struct Node* temp;
    temp = root;
    if(temp == NULL){
        printf("\n\nList is Empty\n\n");
    }
    else{
        printf("\n\nLinked List Data\n");
        while(temp != NULL)
        {
            printf("%d-->",temp->data);
            temp = temp->link;
        }
        printf("\n\n");
    }
}
void delete(void)
{
    
    struct Node* temp;
    int loc;

    printf("Enter location to be detele\n");
    scanf("%d",&loc);

    if(loc>length()){
        printf("Invalid\n");
    } 
    else if(loc == 1)
    {
        temp=root;
        root = temp->link;
        temp->link  = NULL;
        free(temp);
    }
    else{
        struct Node* p=root,*q;
        int i=1;
        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);
    }
}
void reverse()
{
    int i=0,j,k;
    struct Node *p,*q;
    int temp;
    int len;
    len=length();
    j=len-1;
    p=q=root;

    while(i<j)
    {
        k=0;
        while(k<j)
        {
            q=q->link;
            k++;
        }
        temp=p->data;
        p->data=q->data;
        q->data=temp;
        i++;
        j--;
        p=p->link;
        q=root;
    }
        
}
