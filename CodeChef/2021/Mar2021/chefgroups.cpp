#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string str;
        getline(cin, str);
        int length = str.length();
        int max = 0, i = 0;
        bool flag = false;
        while (i < length)
        {
            if (str[i] - '0' == 1)
                flag = true;
            if (str[i] - '0' == 0)
                if (flag == true){
                    max++;
                    flag = false;
                }
            i++;
        }
        if (str[length - 1] - '0' == 1)
            max++;
        cout << max << "\n";
    }
    return 0;
}