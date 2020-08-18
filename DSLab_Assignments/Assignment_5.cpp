#include<iostream>
#include<string>
#include<cctype>

using namespace std;

class string_op{
    public:
        void frequency(string);
        void Delete(string);
        void chardelete(string);
        void palindrome(string);
}; 

void string_op :: frequency(string str){
    cout<<"The String Is : "<<str<<endl;
    cout<<"Enter A Character : ";
    char ch;
    int count=0;
    cin>>ch;
    for(int i=0;i<str.length();i++){
        if(tolower (ch) == tolower(str[i]))
            count++;
    }
    cout<<"Frequency = "<<count<<endl;
}
void string_op :: Delete(string str){}
void string_op :: chardelete(string str){}
void string_op :: palindrome(string str){}

int main(){
    string_op obj;
    string str ;
    cout<<"Enter any String : ";
    getline(cin,str);
    int ch,t=1;
    
    while(t!=0){
        cout<<"Choose An Operation :-\n1.Frequency()\n2.Delete()\n3.CharDelete()\n4.Palindrome()\n5.Exit(0)\n";
        cin>>ch;
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
                t=0;
                break;
            default:
                cout<<"Enter Value Again"<<endl;
                break;
        }
    }
    return 0;
}