#include <iostream>
#include <String>
#include <cmath>
#include <stack>
using namespace std;

int Calculate(char optr, int op1, int op2) { //Op1&Op2 Order For PreFix
    if (optr == '+')
        return op1 + op2;
    if (optr == '-')
        return op1 - op2;
    if (optr == '*')
        return op1 * op2;
    if (optr == '/')
        return op1 / op2;
}

int Evaluate_PreFix(string exp) {
    stack <int> S;
    int op1, op2;
    int res = 0;
    for (int i = exp.length() - 1; i >= 0; i--) {
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
    cout << "Enter A Prefix String : ";
    cin >> exp;
    cout << "Answer Of Prefix : " << Evaluate_PreFix(exp);
    return 0;
}

/*Sample Input :
    Enter A Prefix String : -+*23*549
    Answer Of Prefix : 17
*/