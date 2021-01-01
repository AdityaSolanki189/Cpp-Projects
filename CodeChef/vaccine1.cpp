#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d1,d2,v1,v2,p;
    cin>>d1>>v1>>d2>>v2>>p;
    
    if(d1<d2){
        if(p/v1 < (d2-d1))
            cout<<d1-1 + p/v1 + (p%v1 > 0);
        else if((p-(d2-d1)*v1) % (v1+v2) > 0)
            cout<<d1-1 + d2-d1 + ((p-(d2-d1)*v1)/(v1+v2)) + 1;
        else 
            cout<<d1-1 + d2-d1 + ((p- (d2-d1)*v1)/ (v1+v2));
    }
    else{
        if(p/v2 < (d1-d2))
            cout<<d2-1 + p/v2 + (p%v2 > 0);
        else if((p-(d1-d2)*v2) % (v1+v2) > 0)
            cout<<d2-1 + d1-d2 + ((p-(d1-d2)*v2)/(v1+v2)) + 1;
        else 
            cout<<d2-1 + d1-d2 + ((p- (d1-d2)*v2)/ (v1+v2));
    }

    return 0;
}