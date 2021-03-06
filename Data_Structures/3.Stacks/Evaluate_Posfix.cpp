#include <iostream>
#include <String>
#include <cmath>
#include <stack>
using namespace std;

int Calculate(char optr, int op2, int op1) {  //Op1&Op2 Order For PostFix
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

int Evaluate_PostFix(string exp) {
    stack <int> S;
    int op1, op2;
    int res = 0;
    for (int i = 0; i <= exp.length() - 1; i++) {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            op1 = S.top();
            S.pop();
            op2 = S.top();
            S.pop();
            res = Calculate(exp[i], op1, op2);
            S.push(res);
        }
        else {
            S.push(exp[i] - '0'); //CONVERT CHAR NUMBER TO INT NUMBER 
        }
    }
    return S.top();
}

int main() {
    string exp;
    cout << "\nEnter A PostFix String : ";
    cin >> exp;
    cout << "\nAnswer Of PostFix : " << Evaluate_PostFix(exp);
    cout<<endl;
    return 0;
}

/*Sample Input :
    Enter A PostFix String : 23*54*+9-
    Answer Of Postfix : 17
*/