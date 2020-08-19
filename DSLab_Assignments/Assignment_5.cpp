#include <iostream>
#include <string>
#include <cctype>

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
        if (tolower(ch) == tolower(str[i]))
            count++;
    }
    cout << "Frequency = " << count << endl;
}

void string_op::Delete(string str){
    int j, k;
    cout << "The OG String : " << str << endl;
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
    cout << "The OG String : " << str << endl;
    char ch, new_str[100];
    cout << "Enter Any Character From The String : ";
    cin >> ch;
    for (int i = 0, j = 0; i < str.length(); i++) {
        if (tolower(ch) != tolower(str[i])) {
            str[j++] = str[i];
        }
    }
    cout << "The New String : " << str << endl;
}

void string_op::palindrome(string str) {}

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