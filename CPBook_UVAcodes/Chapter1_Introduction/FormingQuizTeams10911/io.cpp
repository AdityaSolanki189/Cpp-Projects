#include <bits/stdc++.h>
 
#define pii             pair <int,int>
#define sc              scanf
#define pf              printf
#define Pi              2*acos(0.0)
#define ms(a,b)         memset(a, b, sizeof(a))
#define pb(a)           push_back(a)
#define MP              make_pair
#define db              double
#define ll              long long
#define EPS             10E-10
#define ff              first
#define ss              second
#define sqr(x)          (x)*(x)
#define D(x)            cout<<#x " = "<<(x)<<endl
#define VI              vector <int>
#define DBG             pf("Hi\n")
#define MOD             100007
#define MAX             10000
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)           (int)a.size()
#define sf(a)           scanf("%d",&a)
#define sfl(a)          scanf("%lld",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sffl(a,b)       scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define loop(i,n)       for(int i=0;i<n;i++)
#define REP(i,a,b)      for(int i=a;i<b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define PRINT_CASE      printf("Case %d: ",z)
#define CASE_PRINT      cout<<"Case "<<z<<": ";
#define all(a)          a.begin(),a.end()
#define intlim          2147483648
#define inf             1000000
#define ull             unsigned long long
 
using namespace std;
/* 
    Abridged Problem Description:

    Let (x, y) be the coordinates of a student’s house on a 2D plane. There are 2N students
    and we want to pair them into N groups. Let di be the distance between the houses
    of 2 students in group i. Form N groups such that cost = N
    i=1 di is minimized.Output the minimum cost. 
    
    Constraints: 1 ≤ N ≤ 8 and 0 ≤ x, y ≤ 1000.

    Sample input:
    N = 2; Coordinates of the 2N = 4 houses are {1, 1}, {8, 6}, {6, 8}, and {1, 3}.

    Sample output:
    cost = 4.83. 

    SOLVED USING : DP + BIT MASKING
*/

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/
 
/*-----------------------Bitmask------------------*/
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N=N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
/*------------------------------------------------*/
 
vector<pii>v;
 
double dp[1<<17][16][2];
int vis[1<<17][16][2];
int n,z;

double dist(pii x, pii y)
{
    return sqrt((1.0*(x.ff-y.ff)*(x.ff-y.ff))+(1.0*(x.ss-y.ss)*(x.ss-y.ss)));
}
 
double call(int mask,int last, int pp)
{   
    if(__builtin_popcount(mask)==2*n) return 0.0;
    
    double &ret=dp[mask][last][pp];
    int &state=vis[mask][last][pp];
    if(state==z) return ret;
    state=z;
    
    double temp=100000000.0;
//  ret=100000000.0;
    if(pp==0)
    {
        loop(i,2*n)
        {
            if(!check(mask,i))
            {
                temp=min(temp,call(Set(mask,i),i,1));
                break;
            }
        }
    }
    else
    {
        loop(i,2*n)
        {
            if(!check(mask,i))
                temp=min(temp,dist(v[last],v[i])+call(Set(mask,i),i,0));
        }
    }
    
    return ret=temp;
}
    
int main()
{   
    freopen("IO_in1.txt","r",stdin);
    freopen("output.txt","w",stdout);
    CIN;
    while(cin>>n && n)
    {
        z++;
        loop(i,2*n)
        {
            /* string str;
            cin>>str; */
            int a,b;
            cin>>a>>b;
            v.pb(MP(a,b));
        }
        CASE_PRINT;
        cout<<setprecision(2)<<fixed<<call(0,0,0)<<endl;
        v.clear();
    }
    return 0;
}