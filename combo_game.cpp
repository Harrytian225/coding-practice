#include<iostream>
using namespace std;
const int p=10007;
int n,a,b,pb[200002],f[200002];//f[i]是只考虑前i个目标时获得分数的期望值
int inv[p];//数论倒数
/*
递归:f[i]=(1-pb[i])f[i-1]+pb[i](1-pb[i-1])(f[i-2]+1^3)+pb[i]pb[i-1](1-pb[i-2])(f[i-3]+2^3)
+......+pb[i]pb[i-1]...pb[2](1-pb[1])(f[0]+(i-1)^3)+pb[i]pb[i-1]...pb[1]*i^3
*/
int main(){
	cin>>n;
	inv[1]=1;
	for(int i=2;i<=p-1;i++){
		inv[i]=(-(p/i)*inv[p%i])%p;
	}
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		pb[i]=a*inv[b]%p;
	}
	f[1]=pb[1];
	f[2]=(pb[1]+pb[2]+6*pb[1]%p*pb[2]%p)%p;
	f[3]=((1-pb[3])*f[2]%p+pb[3]*(1-pb[2])%p*f[1]%p+pb[3]+7*pb[2]%p*pb[3]%p+19*pb[3]%p*pb[2]%p*pb[1]%p)%p;
	for(int i=1;i<=n-3;i++){
		f[i+3]=((2*pb[i+3]+1)%p*f[i+2]%p-pb[i+3]*(2+pb[i+2])%p*f[i+1]%p+pb[i+3]*pb[i+2]%p*f[i]%p+pb[i+3]%p+4*pb[i+3]%p*pb[i+2]%p+pb[i+3]%p*pb[i+2]%p*pb[i+1]%p)%p;
	}
	cout<<(f[n]+p)%p;
}
