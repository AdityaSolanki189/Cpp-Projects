#include <iostream>
using namespace std;

class Matrix
{
    public:
    int A[10][10],B[10][10],C[10][10], i, j;

    public:
    void accept(int, int);
    void display(int, int);
    void saddle(int, int);
};

void Matrix::accept(int r, int c)
{
    cout<<"Enter Matrix 1\n";
    
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cin>>A[i][j];
        }
    }
    
    cout<<"Enter Matrix 2\n";
    
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cin>>B[i][j];
        }
    }
}

void Matrix::display(int r, int c)
{
    cout<<"Matrix 1 is:\n";
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++){
            cout<<"     "<<A[i][j]  <<"     ";
        }
        cout<<endl;
    }
    
    cout<<"Matrix 2 is:\n";
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++){
            cout<<"     "<<B[i][j]  <<"     ";
        }
        cout<<endl;
    }
}

void Matrix::saddle(int r, int c)
{
    int small[50], big[50], min, max;
    // check for the smallest element in the row
    for(i=0; i<r; i++)
    {
        small[i]=A[i][0];
        
        for(j=0; j<c; j++)
        {
            if (small[i]>A[i][j])
            {
                small[i]=A[i][j];
            }
        }
    }
    // check for the largest element in the column
    for(j=0; j<r; j++)
    {
        big[j]=A[0][j];
        
        for(i=0; i<r; i++)
        {
            if (big[j]<A[i][j])
            {
                big[j]=A[i][j];
            }
        }
    }
    
    max=small[0];
    for(j=0; j<c; j++)
    {
        if (max<small[j])
        {
            max=small[j];
        }
    }
    
    min=big[0];
    for(i=0; i<r; i++)
    {
        if (min>big[i])
        {
            min=big[i];
        }
    }
    
    if (max==big[0])
    {
        cout<<"Saddle Point is present\n\n"<<endl;
    }
    else
    {
        cout<<"Saddle Point is Not present\n\n"<<endl;
    }
    
}

int main()
{
    Matrix obj;
    int row, col;
    int choice;

    do{
        cout<<" 1.Accept\n 2.Display\n 3.Saddle Point\n\n";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
            cout<<"Enter number of rows:";
            cin>>row;

            cout<<"Enter number of columns:";
            cin>>col;
            
            obj.accept(row, col);
            obj.display(row, col);

            break;
            }

            case 2:
            {
                obj.display(row, col);
                break;
            }
            
            case 3:
            {
                obj.saddle(row, col);
                break;
            }
            
            default:
            {
                cout<<"Invalid input";
            }
        }
    }
        
    while(choice<4);
    
    
    return 0;
    
}
