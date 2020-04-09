#include <stdio.h>
#include <stdlib.h>

int main()
    {
        int maxweight, n;
        double s=0;
        scanf("%d %d",&n ,&maxweight);
        int ar[n][2];
        double avg[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&ar[i][0],&ar[i][1]);
            avg[i]=(double)ar[i][0]/ar[i][1];
        }
        int t1,t2,t3;
            for(int i=0;i<n-1;i++)
            {
                for(int j=0;j<n-i-1;j++)
                {
                    if(avg[j]>avg[j+1])
                    {
                        t3=avg[j];
                        avg[j]=avg[j+1];
                        avg[j+1]=t3;

                        t1= ar[j][1];
                        ar[j][1]=ar[j+1][1];
                        ar[j+1][1]=t1;

                        t2= ar[j][0];
                        ar[j][0]=ar[j+1][0];
                        ar[j+1][0]=t2;
                    }
                }
            }

        for(int i=n-1;i>=0;i--)
        {
            if(maxweight==0){
                break;
            }
            else{

                if(maxweight<ar[i][1]){
                    s = s+ avg[i]*maxweight;
                    maxweight = 0;
                    break;
                }
                else if(maxweight>=ar[i][1]){
                    s = s+ avg[i]*ar[i][1];
                }
                maxweight = maxweight-ar[i][1];
            }
        }
        printf("%lf",s);
        return 0;

    }



