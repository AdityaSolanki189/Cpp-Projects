#include <iostream>
using namespace std;

int main()
{
    char a[6];
    int p[4] = {0, 0, 0, 0};
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
    }

    while (p[0] < 6)
    {
        //cout << "\t" << p[0] << p[1] << p[2] << p[3];
        cout << "\t" << a[p[0]] << a[p[1]] << a[p[2]] << a[p[3]];
        p[3]++;
        if (p[3] >= 6)
        {
            p[3] = 0;
            p[2]++;
            if (p[2] >= 6)
            {
                p[2] = 0;
                p[1]++;
                if (p[1] >= 6)
                {
                    p[1] = 0;
                    p[0]++;
                }
            }
        }
    }

    return 0;
}