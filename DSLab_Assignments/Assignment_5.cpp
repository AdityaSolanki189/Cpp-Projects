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
        if(ch==tolower(str[i]))
            count++;
    }
    cout<<"Frequency = "<<count;
}

/* void string_op:: delete_ch(string_op str){
    int j,k;
    cout<<"Enter Positions Of Any 2 Characters you want to delete : "<<endl;
    cin>>j>>k;

}  */

int main(){
    string_op obj;
    string str ;
    cout<<"Enter any String : "<<endl;
    getline(cin,str);
    int ch,t=1;
    cout<<"Choose An Operation :-\n1.Frequency()\n2.Delete()\n3.CharDelete()\n4.Palindrome()\n5.Exit(0)";
    while(t!=0){
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