#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    int a[50];
    int ch, n;
    int i, j, temp;
    cout << "Enter Number Of Elements :" << endl;
    cin >> n;
    cout << "Enter The Numbers : " << endl;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    int num = 1;
    while (num != 0) {
        cout << "Choose an Operation :" << endl;
        cout << "1. Descending Order" << endl;
        cout << "2. Ascending Order" << endl;
        cout << "ENTER 0 TO EXIT " << endl;
        cin >> ch;

        switch (ch) {

        case 1:
            for (i = 1; i < n; i++) {
                for (j = 0; j < (n - i); j++) {
                    if (a[j] < a[j + 1]) {
                        temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                }
            }
            cout << "Array after bubble sorting: " << endl;
            for (i = 0; i < n; i++) {
                cout << " " << a[i] << endl;
            }
            break;

        case 2:
            for (i = 1; i < n; ++i)
            {
                for (j = 0; j < (n - i); ++j)
                    if (a[j] > a[j + 1])
                    {
                        temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
            }

            cout << "Array after bubble sorting: "<< endl;
            for (i = 0; i < n; ++i) {
                cout << " " << a[i] << endl;
            }
            break;

        default:
            num = 0;
            break;
        }
    }
    return 0;
}
