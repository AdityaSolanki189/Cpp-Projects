/* 
    Polynomial Operations Using Operator Overloading 
*/

#include<iostream>
using namespace std;

struct polynomial{
    int coef;
    int expo;
};

class poly{
    public:
        polynomial poly_array[100];
        int total_terms;
        poly(){
            total_terms = 0;
        }
        void accept();
        void display();
        double evaluate(double value);
        poly operator +(poly obj1);
        poly operator *(poly obj2);
};

void poly :: accept(){
    cout<<"Enter Total Number Of Terms : ";
    cin>>total_terms;
    for(int i=0;i<total_terms;i++){
        cout<<"Enter Power Of "<<i+1<<" Term : ";
        cin>>poly_array[i].expo;
        cout<<"Enter Coefficient Of "<<i+1<<" Term : ";
        cin>>poly_array[i].coef;
    }
}

void poly :: display(){
    for(int i=0;i<total_terms;i++){
        cout<<poly_array[i].coef<<"x^"<<poly_array[i].expo<<" + ";
    }
    cout<<endl;
}

int main(){
    poly A,B,C,D;
    double ans;
    int ch,t=1,x;
    while(t){
        cout<<"Polynomial Operations :-\n1.Accept Polynomials\n2.Display Polynomials\n3.Add Polynomials\n4.Multiply Polynomials\n5.Evaluate\n6.Exit\n";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter First Polynomial :"<<endl;
            A.accept();
            cout<<"Enter Second Polynomial :"<<endl;
            B.accept();
            break;
        
        case 2:
            cout<<"The First Polynomial :"<<endl;
            A.display();
            cout<<"The Second Polynomial :"<<endl;
            B.display();
            break;
        
        case 3:
            C = A+B;
            cout<<"Sum Of The Polynomials :"<<endl;            
            C.display();
            break;
        
        case 4:
            D = A*B;
            cout<<"Product Of The Polynomaials :"<<endl;
            D.display();
            break;
        
        case 5:
            cout<<"Enter Value Of X : ";
            cin>>x;
            ans = C.evaluate(x);
            cout<<"The Value Of Polynomial At X = "<<x<<" is "<<ans<<endl;
            break;
        
        case 6:
            t = 0;
        break;

        default:
            cout<<"Invalid Input!";
            break;
        }
    }
}