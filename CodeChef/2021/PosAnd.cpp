#include <iostream>
using namespace std;

int checkpowertwo(int a){
    return a!=0 && ((a&(a-1))==0);
}

int main() {
    
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    if(n==1) {
	        cout<<"1"<<endl;
	        continue;
	    }
	    else if(n==3) {
	        cout<<"1 3 2"<<endl;
	        continue;
	    }
	    else if(n==5){
	        cout<<"2 3 1 5 4"<<endl;
	        continue;
	    }
	    else if(checkpowertwo(n)){ //2,4,8,16,32,64,128,256......
	        cout<<"-1"<<endl;
	        continue;
	    }
	    
	    else{
	        cout<<"2 3 1 5 4 ";
	        for(int i=6;i<=n;){
	            if(checkpowertwo(i)){
	                cout<<i+1<<" "<<i<<" ";
	                i+=2;
	            }
	            else{
	                cout<<i<<" ";
	                i++;
	            }
	        }
	        cout<<endl;
	    }
	}
	return 0;
}
