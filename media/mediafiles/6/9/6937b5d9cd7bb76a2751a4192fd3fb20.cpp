#include<bits/stdc++.h>
using namespace std;

#define MOD 100000000
#define ll long long
ll dp[105][105][15][15];

ll findfun(int f,int h,int kf,int kh){
	if(f+h==0) return 1;
	ll ans=0;
	if(dp[f][h][kf][kh]!=-1) return dp[f][h][kf][kh];
	if(f>0 && kf>0) ans = (ans+findfun(f-1,h,kf-1,kh))%MOD;
	if(h>0 && kh>0) ans = (ans+findfun(f,h-1,kf,kh-1))%MOD;
	return dp[f][h][kf][kh] = ans % MOD;
}


int main(int argc, char const *argv[])
{
	int n1,n2,k1,k2;
	cin>>n1>>n2>>k1>>k2;
	memset(dp,-1,sizeof(dp));
	cout<<findfun(n1,n2,k1,k2);
	return 0;
}