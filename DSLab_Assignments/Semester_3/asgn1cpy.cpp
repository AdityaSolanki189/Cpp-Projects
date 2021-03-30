#include <iostream>
using namespace std;
#define s 10

class matrix
{
protected:
    int a[s][s], b[s][s], x1, y1;

public:
    void get();
    void addition();
    void subtraction();
    void multiplication();
};

void matrix ::get()
{
    cout << "Enter Order Of Matrix : ";
    cin >> x1 >> y1;
    cout << "Matrix A:" << endl;
    cout << "Enter Elements : " << endl;
    for (int i = 0; i < x1; i++)
    {
        for (int j = 0; j < y1; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Matrix B :" << endl;
    cout << "Enter Elements : " << endl;
    for (int i = 0; i < x1; i++)
    {
        for (int j = 0; j < y1; j++)
        {
            cin >> b[i][j];
        }
    }
}

void matrix ::addition()
{
    int result[s][s];
    for (int i = 0; i < x1; i++)
    {
        for (int j = 0; j < y1; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    //display(result,x1,y1);
    for (int i = 0; i < x1; i++)
    {
        for (int j = 0; j < y1; j++)
        {
            cout << " " << result[i][j] << " ";
        }
        cout << endl;
    }
}

void matrix ::subtraction()
{
    int result[s][s];

    for (int i = 0; i < x1; i++)
    {
        for (int j = 0; j < y1; j++)
        {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    //display(result,x1,y1);
    for (int i = 0; i < x1; i++)
    {
        for (int j = 0; j < y1; j++)
        {
            cout << " " << result[i][j] << " ";
        }
        cout << endl;
    }
}

void matrix ::multiplication()
{
    int result[s][s];

    for (int i = 0; i < x1; i++)
    {
        for (int j = 0; j < y1; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < y1; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    //display(result,x1,y1);
    for (int i = 0; i < x1; i++)
    {
        for (int j = 0; j < y1; j++)
        {
            cout << " " << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    char option;
    matrix obj;
    int temp = 1;
    while (temp)
    {
        cout << "\nSelect Option : \n1.Accept Matrix\n\n2.Matrix Addition\n3.Matrix Subtraction\n4.Matrix Multiplication\n5.Exit\n";
        cin >> option;
        switch (option)
        {
        case '1':
            cout << "Accept Matrix A and B :\n";
            obj.get();
            break;
        case '2':
            cout << "Matrix Addition\n";
            obj.addition();
            break;

        case '3':
            cout << "Matrix Subtraction\n";
            obj.subtraction();
            break;

        case '4':
            cout << "Matrix Multpication\n";
            obj.multiplication();
            break;

        case '5':
            temp = 0;
            break;

        default:
            cout << "Enter a valid option\n"
                 << endl;
        }
    }
}