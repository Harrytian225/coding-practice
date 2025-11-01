#include<iostream>
using namespace std;
const int N=300002;
int n,x,y,a[4*N],b[4*N],c[4*N],len=1; //a[i] records possible x values, len is the length of array a[i]
int dp[2*N]; //Initialization: dp[N] = 0
int mem[4*N]; //Bucket, records which numbers are stored in a[i]
int main()
{
    ios::sync_with_stdio (false);
    scanf ("%d", &n);
    for(int j=0;j<=2*N-1;j++)dp[j]=-N;
    dp[N]=0;
    mem[2*N]=1;
    for(int i=1;i<=n;i++){
        scanf ("%d%d", &x, &y);
        if(x>=0)for(int j=0;j<len;j++)dp[N+a[j]+x]=max(dp[N+a[j]+x],dp[N+a[j]]+y);
        else for(int j=len-1;j>=0;j--)dp[N+a[j]+x]=max(dp[N+a[j]+x],dp[N+a[j]]+y);                
        memset(mem,0,sizeof(mem));        
        int pt=len;
        for(int j=0;j<len;j++){
            b[j]=a[j];
            mem[a[j]+2*N]=1;
        }
        for(int j=0;j<len;j++){
            if(mem[b[j]+x+2*N]==0){
                mem[b[j]+x+2*N]=1;
                b[pt]=b[j]+x;
                pt++;
            }
        }
        
        int u=0,v=len,w=0;
        while(u<len and v<pt){
            if(b[u]>b[v])c[w++]=b[u++];
            else c[w++]=b[v++];
        }
        while(u<len)c[w++]=b[u++];
        while(v<pt)c[w++]=b[v++];
        len=pt;
        for(int j=0;j<len;j++)b[j]=c[j];
        
        int t=0;
        int maxy=-N;
        for(int k=0;k<len;k++){
            if(dp[b[k]+N]>maxy){
                maxy=dp[b[k]+N];
                a[t++]=b[k]; //a[i] is sorted in descending order
            }
            else dp[b[k]+N]=-N;
        }
        len=t;
        
    }
    int ans=0;
    for(int i=0;i<len;i++){
        if(dp[N+a[i]]+a[i]>ans and a[i]>=0 and dp[N+a[i]]>=0){
            ans=dp[N+a[i]]+a[i];            
        }
    }
    cout<<ans;
}