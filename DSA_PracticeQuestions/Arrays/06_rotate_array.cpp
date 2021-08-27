//CyclicallyRotateAnArrayByOne

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int array[n];
    for(int i=0;i<n;i++) cin >> array[i];

    int temp = array[n-1];
    for(int i=n-1;i>0;i--){
        array[i] = array[i-1];
    }
    array[0] = temp;

    cout << "Array After 1 Rotation : ";
    for(int i=0;i<n;i++) cout << array[i] << " ";
    return 0;
}