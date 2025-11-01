#include<iostream>
using namespace std;
const int N=200002;
int n,p[N];
int son[N],bro[N];
int maxd[N],secondd[N]; // first depth, second depth

void dfs(int node){ // Calculate first and second depth
	for(auto v=son[node];v!=0;v=bro[v]){
		dfs(v);
		int s=maxd[v]+1;
		if(s>maxd[node]){
			secondd[node]=maxd[node];
			maxd[node]=s;
		}
		else if(s>secondd[node])secondd[node]=s; 
	}
}

int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>p[i];
		bro[i]=son[p[i]];
		son[p[i]]=i;
	}
	dfs(1);
	cout<<maxd[1]<<" ";
	for(int i=2;i<=n;i++){ // Calculate max distance and second max distance, stored in maxd and secondd
		int f;
		if(maxd[p[i]]==maxd[i]+1)f=secondd[p[i]]+1;
		else f=maxd[p[i]]+1;
		if(f>maxd[i]){
			secondd[i]=maxd[i];
			maxd[i]=f;
		}
		else if(f>secondd[i])secondd[i]=f;
		cout<<maxd[i]<<" ";
	}
}