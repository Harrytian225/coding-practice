#include<iostream>

using namespace std;
int main(){
	int n,a,b,r;
	cin>>n;
	if(n==1){
		cout<<2<<" "<<1<<endl;
		return 0;
	}
	a=1;
	b=n;
	while(b-a>0){
		int d;
		if((b-a+1)%3==0)d=(b-a+1)/3;
		else d=(b-a+1)/3+1;
		cout<<1<<" "<<d<<" "<<d<<endl;
		for(int i=a;i<=d+a-1;i++)cout<<i<<" ";
		cout<<endl;
		for(int i=d+a;i<=d*2+a-1;i++)cout<<i<<" ";
		cout<<endl;
		cin>>r;
		if(r==1)b=a+d-1;
		else if(r==-1){
			b=a+d*2-1;
			a=a+d;
		}
		else a=d*2+a;
	}
	cout<<2<<" "<<a<<endl;
	return 0;
}