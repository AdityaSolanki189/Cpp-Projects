#include<stdio.h>

int main(){
    int t,arr[1000];
    scanf("%d",&t);
    
    for(int i=0;i<t;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<t;i++){
        int rem=0,rev=0;

        while(arr[i]>0){
            rem = arr[i]%10;
            rev = rem + (rev*10);
            arr[i] = arr[i]/10;
        }
        printf("%d\n",rev);
    }

    return 0;
}