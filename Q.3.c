#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
int data;
struct node*next;
struct node*prev;

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
temp->prev=NULL;
if (head==NULL){
    head=temp;
}
else{

    temp->next=head;
    head->prev=temp;
    head=temp;
}

}
void insert_last(int n){
struct node*temp=(struct node *)malloc(sizeof(struct node));
temp->data=n;
temp->next=NULL;
temp->prev=NULL;
if (head==NULL){
    head=temp;
}
else{
    struct node*temp1=head;
    while(temp1->next!=NULL){
    temp1=temp1->next;
    }
    temp1->next=temp;
    temp->prev=temp1;

}}

void insert_specific(int n){
int num1;
printf("\n Enter the number after which you want to insert :");
scanf("%d",&num1);
struct node*temp=(struct node *)malloc(sizeof(struct node));
temp->data=n;
temp->next=NULL;
temp->prev=NULL;
struct node*temp1=head;
while(temp1!=NULL && temp1->data!=num1){

    temp1=temp1->next;
}
if (temp1==NULL){
 printf("\n element not found :");
}
else
{
    if (temp1->next==NULL){
        temp1->next=temp;
        temp->prev=temp1;
    }
    else{
        temp->next=temp1->next;
        temp1->next->prev=temp;
        temp1->next=temp;
        temp->prev=temp1;
    }
}
}

void del_begin(){
if (head==NULL){
    printf("list is empty");
}
else{
    struct node*temp=head;
    head=head->next;
    if (head!=NULL){
    head->prev=NULL;}
    free(temp);
}


}
void del_last(){
if (head==NULL){
    printf("list is empty");
}
else{
    struct node*temp1=head;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    if(temp1==head){
        head=NULL;
    }
    else
        temp1->prev->next=NULL;
    free(temp1);

}

}
void del_specific(int n){
struct node*temp=head;
if (head==NULL){
    printf("linked list is empty");
}
else{
while(temp!=NULL && temp->data!=n){
    temp=temp->next;
}
if (temp==NULL){
    printf("value is not in list");
}
if(temp->next==NULL && temp==head){
     head=NULL;
    free(temp);
}
else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
}
}
}


void searching(int n){
struct node*temp=head;
while(temp!=NULL && temp->data!=n){
    temp=temp->next;
}
if (temp==NULL){
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
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
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

