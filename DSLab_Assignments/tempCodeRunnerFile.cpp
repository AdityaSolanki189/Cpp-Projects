void matrix ::display(int arr[][], int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; i++)
        {
            cout << " " << arr[i][j] << " ";
        }
        cout << endl;
    }
}