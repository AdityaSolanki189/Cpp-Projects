//W-Capacity, n-number of itmes, v-number of itmes, w- weight of items respectively 

#include <iostream>  
#include <math.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

using namespace std;

int main(){
    int W,n,v[2000000],w[2000000],avg[100];
    scanf("%d%d",&W,&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&v[i],&w[i]);
    }
    sort_avg(n,)
    knapsack(W,v,w);

    return 0;
}
void knapsack(int n, int v[], int w[]){
    int A=0,V=0;
    int max_per_unit = maximum(n,v,w);

}
int maximum(int n,int v[],int w[]){
    int max=0
    double cmp = 0;
    for(int i = 0; i < n; i++){
        if(w[i] > 0 && max(v, v[i]/a[i]) == v[i]/a[i]){
            max = i;
            cmp = v[i]/a[i];
        }
    }
    return max;
}
void sort_weight(int n,int v[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j+1<n-i;j++){
            if(v[j]>v[j+1]){
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }          
    }
}
void sort_a(int n,int a[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j+1<n-i;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }          
    }
}