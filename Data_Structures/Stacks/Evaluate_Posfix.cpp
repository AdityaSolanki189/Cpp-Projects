#include <iostream>
#include <String>
#include <stack>
using namespace std;

int Calculate(int oper,int op1,int op2){
    if(oper == "+")
        return op1+op2;
    else if(oper == "-")
        return op1-op2;
    else if(oper == "*")
        return op1*op2;
    else if(oper == "/")
        return op1/op2;   
}

int Evaluate_PostFix(string exp){
    stack <int> S;
    int op1=0,op2=0,res=0;
    for(int i=0;i<exp.length()-1;i++){
        if(exp[i] == "+" || exp[i] == "-" || exp[i] == "*" || exp[i] == "/"){
            op1 = s.pop();
            op2 = s.pop();
            res = Calculate(exp[i],(int)op1,(int)op2);
            s.push(res);
        }
        else{
            s.push(exp[i]);
        }
    }
    return s.top();
}

int main(){
    string exp;
    cout<<"Enter A PostFix String : ";
    getline(cin,exp);
    cout<<Evaluate_PostFix(exp);
    return 0;
}

/*Sample Input :
    Enter A PostFix String : 23*54*+9-
    Answer Of Postfix : 17
*/