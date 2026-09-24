#include<stdio.h>
#include<stdlib.h>
struct node{
    int data ;
    struct node * next ;
};
struct node * new, *top, *t;
void push( int x){
    new = (struct node*)malloc(sizeof(struct node));
    new->data =x;
    new->next = top;
    top= new;
}
void pop(){
    if (top==NULL){
        printf("stack underflow\n");
    }
    else{
        t= top;
        top = top->next;
        printf("deleted element is %d\n",t->data);
        free(t);
        t=NULL;
    }
}
    void main(){
        top = NULL;
        push(10);
        push(20);
        push(30);
        push(40);
        pop();
        pop();
    }
