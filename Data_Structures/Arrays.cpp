#include<iostream>

using namespace std;

class Array{
    private:
        int MaxSize;
        int A[20];
        int Size;
    public:
        Array(){ //constructor
            MaxSize = 20;
            Size = 0;
        }
        void Read_Array();
        void Display_Array();
        void Traverse_Back();
        void Insert_Element();
        void Delete_Element();
        void Search_Element();
};
void Array :: Read_Array(){
    cout<<"Enter The Size (<20) : ";
    cin>>Size;
    for(int i=0;i<Size;i++) cin>>A[i];
    Display_Array();
}
void Array :: Display_Array(){
    for(int i=0;i<Size;i++) cout<<A[i]<<" ";
    cout<<endl;
}
void Array :: Traverse_Back(){
    for(int i=Size-1;i>=0;i--) cout<<A[i]<<" ";
    cout<<endl;
}
void Array :: Insert_Element(){
    int location, element;
    cout<<"Enter The Location : ";
    cin>>location;
    cout<<"Enter The Element : ";
    cin>>element;
    if(Size >= MaxSize){
        cout<<"Error : Memory Overflow";
        return;
    }
    for(int i=Size-1;i>=location-1;i--){
        A[i+1] = A[i];
    }
    A[location-1] = element;
    Size = Size+1;
    Display_Array();
}
void Array :: Delete_Element(){
    int location;
    cout<<"Enter The Location Of The Element You Want To Delete : ";
    cin>>location;
    for(int i=Size-1;i>=location-1;i--){
        A[i] = A[i+1];
    }
    Size--;
    Display_Array();
}
void Array :: Search_Element(){
    int search;
    cout<<"Enter Any Element From The Array : ";
    cin>>search;
    for(int i=0;i<Size;i++){
        if(search==A[i]){
            cout<<"First Occurance Of Element "<<search<<" Found At : "<<i+1<<endl;
            return;
        }
    }
    cout<<"No Occurance Of The Given Element Found!";
}
int main(){
    Array a;
    a.Read_Array();
    a.Traverse_Back();
    a.Insert_Element();
    a.Delete_Element();
    a.Search_Element();
}