/* 
    Aditya Solanki CSE 3 [2193023]
    Polynomial Operations Using Operator Overloading 
*/

#include<iostream>
#include<cmath>
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
        double evaluate(double);
        poly operator +(poly);
        poly operator *(poly);
};

void poly :: accept(){
    cout<<"Enter Total Number Of Terms : ";
    cin>>total_terms;
    cout<<endl;
    for(int i=0;i<total_terms;i++){
        cout<<"Enter Coefficient Of "<<i+1<<" Term : ";
        cin>>poly_array[i].coef;
        cout<<"Enter Power Of "<<i+1<<" Term : ";
        cin>>poly_array[i].expo;
        cout<<endl; 
    }
}

void poly :: display(){
    for(int i=0;i<total_terms;i++){
        cout<<poly_array[i].coef<<"x^"<<poly_array[i].expo<<" ";
    }
    cout<<endl;
}

double poly :: evaluate(double value){
    int i=total_terms;
    double result = 0;
    while(i--){
        result += poly_array[i].coef*pow(value,poly_array[i].expo);
    }
    return result;
}

poly poly :: operator+(poly B){
    int k=0,i=0,j=0;
    poly C;
    while(i<total_terms && j<B.total_terms){
        if(poly_array[i].expo == B.poly_array[j].expo){
            C.poly_array[k].coef = poly_array[i].coef + B.poly_array[j].coef;
            C.poly_array[k].expo = poly_array[i].expo;
            i++;
            j++;
            k++;
        }
        else if(poly_array[i].expo > B.poly_array[j].expo){
            C.poly_array[k].coef = poly_array[i].coef;
            C.poly_array[k].expo = poly_array[i].expo;
            i++;
            k++;
        }
        else {  //(poly_array[i].expo < B.poly_array[j].expo)
            C.poly_array[k].coef = B.poly_array[j].coef;
            C.poly_array[k].expo = B.poly_array[j].expo;
            j++;
            k++;
        }
    }
    while(i<total_terms){
        C.poly_array[k].coef = poly_array[i].coef;
        C.poly_array[k].expo = poly_array[i].expo;
        i++;
        k++;
    }
    while(j<total_terms){
        C.poly_array[k].coef = B.poly_array[j].coef;
        C.poly_array[k].expo = B.poly_array[j].expo;
        j++;
        k++;
    }
    C.total_terms = k;
    return C;
}

poly poly :: operator*(poly B){
    poly D; // stores product of the polynomials
    int prod_terms = total_terms * B.total_terms;
    int k=0;
    for (int i=0; i<total_terms; i++){
        // Multiply the current term of first polynomial with every term of second polynomial. 
        for (int j=0; j<B.total_terms; j++){
            D.poly_array[k].coef = poly_array[i].coef*B.poly_array[j].coef;
            D.poly_array[k].expo = poly_array[i].expo+B.poly_array[j].expo;
            k++;
        }
    }
    D.total_terms = total_terms*B.total_terms;    
    return D;
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
            cout<<endl;
            cout<<"Enter Second Polynomial :"<<endl;
            B.accept();
            cout<<endl;
            break;
        
        case 2:
            cout<<"The First Polynomial :"<<endl;
            A.display();
            cout<<endl;
            cout<<"The Second Polynomial :"<<endl;
            B.display();
            cout<<endl;
            break;
        
        case 3:
            C = A+B;
            cout<<"Sum Of The Polynomials :"<<endl;            
            C.display();
            cout<<endl;
            break;
        
        case 4:
            D = A*B;
            cout<<"Product Of The Polynomaials :"<<endl;
            D.display();
            cout<<endl;
            break;
        
        case 5:
            cout<<"Enter Value Of X : ";
            cin>>x;
            A.display();
            ans = A.evaluate(x);
            cout<<"The Value Of Polynomial At (X = "<<x<<") is "<<ans<<endl;
            cout<<endl;
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