#include<stdio.h>
int stack[100];
int top=-1;
void push (int x){
    stack[++top]=x;
}
int pop(){
    return stack[top--];
}
int isDigit(char ch){
    return ch>='0' && ch<='9';
}
int main(){
    char exp[100];
    int i,a,b,result;
    printf("enter infix expression:");
    scanf("%s",exp);
    fo(i=0;exp[i]!='\0';i++){
        if(isDigit(exp[i])){
            push(exp[i]-'0');
        }
        else if (exp[i]=='('){

        }
        else if(exp[i]== '+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
            b= pop();
            a=pop();
            switch(exp[i]){
                case '+':result = a+b;break;
                case '-':result = a-b;break;
                case '*':result = a*b;break;
                case '/':result = a/b;break;
            }
            push(result);
        }
    }
    printf("Result = %d\n",pop());
    return 0;
}
