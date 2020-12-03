/*
    WAP in C++ for expression conversion from infix to postfix 
    and Evaluate using Stack Data Structure.
    #Condition : Only '+','-','*','/' and '^' are expected
*/
#include <iostream>
#include <string>
#include <cctype>
#define MAX 20
using namespace std;

class Convert{
    char stk[MAX];
    int top;
    public:
    void push(char);
    char pop();
    char top_();
    int priority(char);
    bool precedence(char,char);
    bool empty();
    string infix_to_postfix(string);
    Convert(){
        top = -1;
    }
};

void Convert :: push(char oper){
    if(top==MAX-1){
        cout<<"Stack Is FuLL!\n";
    }
    else{
        top++;
        stk[top]=oper;
    }
}

char Convert :: pop(){
    char ch;
    if(top==-1){
        cout<<"Stack Is Empty!";
    }
    else{
        ch=stk[top];
        stk[top]='\0';
        top--;
        return(ch);
    }
    return 0;
}

char Convert :: top_(){
    return(stk[top]);
}

bool Convert :: precedence(char op1, char op2){
    if(priority(op1)>=priority(op2)){
        return true;
    }
    else{
        return false;
    }
}

int Convert :: priority(char alpha){
    
    if(alpha == '+' || alpha =='-'){
        return(1);
    }
    if(alpha == '*' || alpha =='/'){
        return(2);
    }
    if(alpha == '^'){
        return(3);
    }
    return 0;
}

bool Convert :: empty(){
    if(top==-1)
        return true;
    else
        return false;
}

string Convert :: infix_to_postfix(string infix){
    string postfix = "";
    int i=0;
    while(infix[i]!='\0'){
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z' ||isdigit(infix[i])){
            postfix += infix[i];
            i++;
        }
        else {
            while(!empty() && precedence(top_(),infix[i])){
                postfix += top_();
                pop();
            }
            push(infix[i]);
            i++;
        }
    }
    while(!empty()){
        postfix += top_();
        pop();
    }
    return postfix;
}


class Evaluate{
    char stk[MAX];
    int top;
    public:
    void push(char);
    void pop();
    char top_();
    int calculate(char,int,int);
    int Evaluate_Postfix(string exp);
    Evaluate(){
        top = -1;
    }
};

void Evaluate :: push(char oper){
    if(top==MAX-1){
        cout<<"Stack Is FuLL!\n";
    }
    else{
        top++;
        stk[top]=oper;
    }
}

void Evaluate :: pop(){
    char ch;
    if(top==-1){
        return;
    }
    else{
        ch=stk[top];
        stk[top]='\0';
        top--;
    }
}

char Evaluate :: top_(){
    return(stk[top]);
}

int Evaluate :: calculate(char optr, int op2, int op1) {  //Op1&Op2 Order For PostFix
    if (optr == '+')
    if (optr == '+')
        return op1 + op2;
    if (optr == '-')
        return op1 - op2;
    if (optr == '*')
        return op1 * op2;
    if (optr == '/')
        return op1 / op2;
    return 0;
}

int Evaluate :: Evaluate_Postfix(string exp){
    int op1, op2;
    int res = 0;
    int i=0;
    while(exp[i]!='\0'){
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            op1 = top_();
            pop();
            op2 = top_();
            pop();
            res = calculate(exp[i], op1, op2);
            push(res);
        }
        else {
            push(exp[i] - '0'); //CONVERT CHAR NUMBER TO INT NUMBER 
        }
        i++;
    }
    return top_();
}

int main(){
    Convert C;
    Evaluate E;
    int t=1;
    string infix,postfix,postfix2;
    while(t){
        cout<<"\nChoose Any One :-\n";
        cout<<"1. Infix To Postfix Conversion.\n";
        cout<<"2. Evaluate Postfix Expression.\n";
        cout<<"3. Exit.\n";
        int ch;
        cout<<"Enter : ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"\nEnter an Infix Expression : ";
                cin.ignore();
                cin>>infix;
                cout<<"\nPostfix Expression : "<<C.infix_to_postfix(infix)<<endl;
            break;

            case 2:
                cout<<"\nEnter a Postfix Expression : ";
                cin.ignore();
                cin>>postfix;
                cout<<"\nAnswer Of Postfix : "<<E.Evaluate_Postfix(postfix)<<endl;
            break;

            case 3:
                t=0;
                cout<<"GGWP";
            break;

            default:
                cout<<"Invalid Input! \n";
            break;
        }
    }
    return 0;
}