#include<iostream>
#include<string.h>
using namespace std;

class string_op{
    public:
        void frequency(string);
}; 

void string_op :: frequency(string str){
    cout<<"The String Is : "<<str<<endl;
    cout<<"Enter A Character : ";
    char ch;
    int count=0;
    cin>>ch;
    for(int i=0;i<str[i]!='\0';i++){
        if(ch==str[i])
            count++;
    }
    cout<<"Frequency = "<<count;
}

/* void string_op:: delete_ch(string_op str){
    int n,j[str.length];
    cout<<"Enter The Number of Characters You Want To Delete : "<<endl;
    cin>>n;
    cout<<"Enter Any "<<n<<" Positions : "<<endl;
    for(int i=0;)

    for(int j=)
} */

int main(){
    string_op obj;
    string str ;
    cout<<"Enter any String : "<<endl;
    cin>>str;
    obj.frequency(str);
    return 0;
}