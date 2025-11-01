#include<iostream>
#include<stack>
using namespace std;
int main(){
	stack<int> stk;
	int n,h[100002],maxa=0;
	cin>>n;
	for(int i=0;i<=n;i++){
		if(i<n)cin>>h[i];
		else h[n]=0;
		if(stk.empty()){
			stk.push(i);
			continue;
		}
		while(!stk.empty() && h[stk.top()]>h[i]){
			int cnt=stk.top();
			stk.pop();
			if(stk.empty())maxa=max(maxa,i*h[cnt]);
			else maxa=max(maxa,h[cnt]*(i-1-stk.top()));
		}
		stk.push(i);
	}
	cout<<maxa<<endl;
	return 0;
}