#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
int data;
struct node*next;

}*head=NULL;

int num(){
int n;
printf("enter the number");
scanf("%d",&n);
return n;
    }
void insert_begin(int n){
struct node*temp=(struct node *)malloc(sizeof(struct node));
temp->data=n;
temp->next=NULL;
if (head==NULL){
    head=temp;
    temp->next=head;

}
else{
    temp->next=head;
    struct node*temp1=head;
    while(temp1->next!=head){
        temp1=temp1->next;
    }
    temp1->next=temp;
    head=temp;
}

}

void insert_last(int n){
struct node*temp=(struct node *)malloc(sizeof(struct node));
temp->data=n;
temp->next=NULL;
if (head==NULL){
    temp->next=temp;
    head=temp;
}
else{
    temp->next=head;
    struct node*temp1=head;
    while(temp1->next!=head){
        temp1=temp1->next;
    }
    temp1->next=temp;

}

}
void insert_specific(int n){
int num1;
printf("\n Enter the number after which you want to insert :");
scanf("%d",&num1);
struct node*temp=(struct node *)malloc(sizeof(struct node));
temp->data=n;
temp->next=NULL;
struct node*temp1=head;
while(temp1->next!=head && temp1->data!=num1){

    temp1=temp1->next;
}
if (temp1->next==head){
 printf("\n element not found :");
}
else
{
    if (temp1->next==NULL){
        temp1->next=temp;
    }
    else{
        temp->next=temp1->next;
        temp1->next=temp;
    }
}
}
void del_begin(){
if (head==NULL){
    printf("list is empty");
}
else{
    struct node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    struct node*temp1=head;
    head=head->next;
    temp->next=head;
    free(temp1);
}


}
void del_last(){
if (head==NULL){
    printf("list is empty");
}
else{
    struct node*temp1=head;
    struct node*pre;
    while(temp1->next!=head){
        pre=temp1;
        temp1=temp1->next;
    }
    if(temp1==head){
        head=NULL;
    }
    else
        pre->next=head;
    free(temp1);

}

}
void del_specific(int n){
struct node*temp=head;
struct node*pre;
while(temp->next!=head && temp->data!=n){
    pre=temp;
    temp=temp->next;
}
if (temp->next==head){
    printf("value is not in list");
}
else{
        pre->next=temp->next;
        free(temp);
}

}
void searching(int n){
struct node*temp=head;
while(temp->next!=head && temp->data!=n){
    temp=temp->next;
}
if (temp->next==head){
    printf("value is not in list");
}
else{
    printf("element found");
}

}
void display(){
if (head==NULL){
    printf("list is empty");
}
else{
    struct node*temp=head;
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}
}
int main(){

int n=1;
int d;
while(n==1){
printf("\n enter the operation you want to perform:");
printf("\n 1.insertion 2.deletion 3.search 4.display : ");
scanf("%d",&d);
int k;
switch(d){
case 1:
    k=num();
    printf("\n where to insert:");
    printf("\n 1.at the beginning   2.at the end  3.in between after specific value : \n ");
    scanf("%d",&d);
    switch(d){
    case 1:
        insert_begin(k);
        break;
    case 2:
        insert_last(k);
        break;
    case 3:
        insert_specific(k);
        break;
    }
    break;
case 2:
    printf("\n From where to delete:");
    printf("\n 1.from the beginning   2.from the end  3.any value in between of lis : \n ");
    scanf("%d",&d);
    switch(d){
    case 1:
        del_begin();
        break;
    case 2:
        del_last();
        break;
    case 3:
        k=num();
        del_specific(k);
        break;
    }
    break;
case 3:
    k=num();
    searching(k);
    break;
case 4:
    display();
    break;
default:
    return 0;
}
printf("\n Type 1 to continue : ");
scanf("%d",&n);

}
return 0;


}





