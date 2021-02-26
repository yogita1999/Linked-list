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
printf("enter the number : ");
scanf("%d",&n);
return n;
}

void insert_last(int n){
struct node*temp=(struct node *)malloc(sizeof(struct node));
temp->data=n;
temp->next=NULL;
if (head==NULL){
    head=temp;
}
else{
    struct node*temp1=head;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=temp;

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
void reverse(){
struct node*current=head;
struct node*prev=NULL;
struct node*next=NULL;
while(current!=NULL){
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
}
head=prev;


}

int main(){

int n=1;
int d;
while(n==1){
int k;
k=num();
insert_last(k);
printf("\n Type 1 to continue : ");
scanf("%d",&n);

}
printf("\n actual linked list \n");
display();
reverse();
printf("\n reversed linked list \n");
display();
return 0;


}





