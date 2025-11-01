#include<iostream>
using namespace std;
const int p=1000000007,N=4194304;
int n,a,b[23];
bool mem[22][N];//Memoized Search 
int val[22][N];

int dfs(int i,int y){//considering ith black dot, previous black dots have benn matched
//y means the status of white dots, 1 means this dot hasn't been matched
	if(i==n)return 1;
	int w=b[i]&y;
	if(w==0)return 0;
	if(mem[i][y])return val[i][y];
	mem[i][y]=true;
	int d=0;
	while(w>0){
		int u=w&(-w);
		d=((long long)((long long)d+(long long)dfs(i+1,y-u)))%p;
		w-=u;	
	}
	val[i][y]=d;
	return d;
}
signed main()
{
	cin>>n;
	int s=(1<<n)-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a;
			b[i]+=(a<<j);
		}
	}
	cout<<dfs(0,s);
}
