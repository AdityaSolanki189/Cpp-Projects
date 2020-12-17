/* 
	PL1 Assignment 5 by Aditya Solanki 
	Roll No. 2193023
	CSE - 3 
 
    Write C++ program for String operations. Write the following functions:
    frequency(): that determines the frequency of occurrence of particular character in the string.
    delete(): that accepts two intergers to specify position of characters to be deleted. The function computes
    new string that is except the deleted characters.
    chardelete(): that accepts a character c. The function returns the string with all occurrences of c removed.
    palindrome(): to check whether given string is palindrome or not
*/

#include <iostream>
#include <string>

using namespace std;

class string_op{
public:
    void frequency(string);
    void Delete(string);
    void chardelete(string);
    void palindrome(string);
};

void string_op::frequency(string str){
    cout << "The String Is : " << str << endl;
    cout << "Enter A Character : ";
    char ch;
    int count = 0;
    cin >> ch;
    for (int i = 0; i < str.length(); i++){
        if (ch == str[i])
            count++;
    }
    cout << "Frequency = " << count << endl;
}

void string_op::Delete(string str){
    int j, k;
    cout << "The Given String : " << str << endl;
    cout << "Enter Any 2 Positions you want to Delete : " << endl;
    cin >> j >> k;
    if (j < k)    {
        for (int i = j; i < str.length(); i++){
            str[i] = str[i + 1];
        }

        for (int i = k - 1; i < str.length(); i++){
            str[i] = str[i + 1];
        }
        cout << "The New String : " << str << endl;
    }
    else if (j == k)    {
        for (int i = k; i < str.length(); i++){
            str[i] = str[i + 1];
        }
        cout << "The New String : " << str << endl;
    }
    else{
        for (int i = j; i < str.length(); i++){
            str[i] = str[i + 1];
        }

        for (int i = k; i < str.length(); i++){
            str[i] = str[i + 1];
        }
        cout << "The New String : " << str << endl;
    }
}

void string_op::chardelete(string str){
    cout << "The Given String : " << str << endl;
    char ch;
    cout << "Enter Any Character From The String : ";
    cin >> ch;
    for (int i = 0; i < str.length(); i++) {
        if(str[i] == ch){
            str[i] = '\0';
        }
    }
    cout << "The New String : " << str << endl;
}

void string_op::palindrome(string str){
    cout << "The Given String : " << str << endl;
    int left=0,right=str.length()-1;
    while(right > left){
        if (str[left++] != str[right--]){ 
            cout<<str<<" Is Not A Palindrome!"<<endl; 
            return; 
        } 
    }
    cout<<str<<" Is A Palindrome!"<<endl;
}

int main(){
    string_op obj;
    string str;
    cout << "\nEnter any String : ";
    getline(cin, str);
    int ch, t = 1;
    while (t != 0){
        cout << "\nChoose An Operation :-\n1.Frequency()\n2.Delete()\n3.CharDelete()\n4.Palindrome()\n5.Exit(0)\n";
        cin >> ch;
        switch (ch){
            case 1:
                obj.frequency(str);
            break;
            case 2:
                obj.Delete(str);
            break;
            case 3:
                obj.chardelete(str);
            break;
            case 4:
                obj.palindrome(str);
            break;
            case 5:
                t = 0;
            break;
            default:
                cout << "Enter Value Again" << endl;
            break;
        }
    }
    return 0;
}