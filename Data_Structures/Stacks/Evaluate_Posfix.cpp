#include <iostream>
#include <String>
#include <stack>
using namespace std;

int Calculate(char optr, int op1, int op2) {
    if (optr == '+')
        return op1 + op2;
    if (optr == '-')
        return op1 - op2;
    if (optr == '*')
        return op1 * op2;
    if (optr == '/')
        return op1 / op2;
}

int Evaluate_PostFix(string exp) {
    stack <int> S;
    char op1, op2;
    int res = 0;
    for (int i = 0; i < exp.length() - 1; i++) {
        if (exp[i] == '+'|| exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            op1 = S.top();
            S.pop();
            op2 = S.top();
            S.pop();
            res = Calculate(exp[i],(int)op1,(int)op2);
            S.push(res);
        }
        else {
            S.push((int)exp[i]);
        }
    }
    return S.top();
}

int main() {
    string exp;
    cout << "Enter A PostFix String : ";
    getline(cin, exp);
    cout << Evaluate_PostFix(exp);
    return 0;
}

/*Sample Input :
    Enter A PostFix String : 23*54*+9-
    Answer Of Postfix : 17
*/