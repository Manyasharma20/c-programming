
#include<stdio.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push (char ch){
    stack[++top]=ch;
}
char pop(){
    return stack[top--];
}
int priority(char ch){
    if(ch=='^')
    return 3;
    if(ch == '*' || ch == '/')
    return 2;
    if(ch == '+' || ch == '-')
    return 1;
 return 0;
}
int isOperand(char ch){
    if((ch >='A' && ch <='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9'))
    return 1;
return 0;
}
int length (char str[]){
    int i =0;
    while(str[i]!='\0')
    i++;
    return i;
}
void reverse(char str[]){
    int i ,j;
    char temp;
    i=0;
    j = length(str)-1;
    while(i<j){
        temp=str[i];
        str[i]= str[j];
        str[j]=temp;
        i++;
        j--;
    }
}
int main(){
    char infix[MAX],prefix[MAX];
    int i ,j=0;
    char ch;
    printf("enter infix exp");
    scanf("%s",infix);
    reverse(infix);
    for(i=0;infix[i]!='\0';i++){
        if(infix[i] == '(')
        infix[i]=')';
        else if(infix[i]==')')
        infix[i]='(';
    }
    for(i=0;infix[i]!='\0';i++){
        ch = infix[i];
        if(isOperand(ch)){
            prefix[j++]=ch;
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch ==')'){
            while(top!= -1 && stack[top]!='(')
            prefix[j++]=pop();
        pop();
        }
        else{
            while(top!=-1 && stack[top]!= '(' && priority (stack[top])>priority(ch)){
                prefix[j++]=pop();
            }
            push(ch);
        }
    }
    while(top!=-1)
    prefix[j++]=pop();
    prefix[j]= '\0';
    reverse(prefix);
    printf("prefix exp:%s",prefix);
    return 0;
}
