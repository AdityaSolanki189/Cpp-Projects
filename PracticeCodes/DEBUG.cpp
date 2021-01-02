#include <iostream>
#include <string.h>
using namespace std;

class Matrix
{
public:
    int i, j;
    int a[3][3];
    void accept(int, int);
    void display(int, int);
    void saddle(int, int);
};

void Matrix::accept(int r, int c)
{
    cout << "Matrix : " << endl;
    for (i = 1; i <= r; i++)
    {
        cout << "Enter row " << i << ":" << endl;
        for (j = 1; j <= c; j++)
        {
            cout << "Enter column " << i << " element " << j << " = ";
            cin >> a[i][j];
        }
    }
}

void Matrix::display(int r, int c)
{
    cout << "Matrix : " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            cout << " " << a[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::saddle(int r, int c)
{
    int small[10], big[10], maxi, mini;
    for (i = 1; i <= r; i++)
    {
        small[i] = a[i][1];
        for (j = 1; j <= c; j++)
        {
            if (small[i] > a[i][j])
            {
                small[i] = a[i][j];
            }
        }
    }
    for (j = 1; j <= c; j++)
    {
        big[j] = a[1][j];
        for (i = 1; i <= r; i++)
        {
            if (big[j] < a[i][j])
            {
                big[j] = a[i][j];
            }
        }
    }
    maxi = small[1];
    for (i = 1; i <= r; i++)
    {
        if (maxi < small[i])
        {
            maxi = small[i];
        }
    }
    mini = big[1];
    for (j = 1; j <= c; j++)
    {
        if (mini > big[j])
        {
            mini = big[j];
        }
    }
    if (maxi == mini)
    {
        cout << "Saddle point exists = " << maxi << endl;
    }
    else
    {
        cout << "Saddle point does not exist" << endl;
    }
}

int main()
{
    Matrix m1, m2, m3;
    int r, c, ch;
    cout << "Enter value for row = ";
    cin >> r;
    cout << "Enter value for col = ";
    cin >> c;
    m1.accept(r, c);
    cout << endl;
    do
    {
        cout << "1.Display  2.Saddle  3.Exit" << endl;
        cout << "Enter choice = ";
        cin >> ch;
        if (ch == 3)
        {
            break;
        }
        switch (ch)
        {
        case 1:
        {
            m1.display(r, c);
            break;
        }
        case 2:
        {
            m1.saddle(r, c);
            break;
        }
        default:
        {
            cout << "Invalid Input" << endl;
            break;
        }
        }
    } while (ch < 3);
    return 0;
}
