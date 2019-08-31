#include<bits/stdc++.h>
using namespace std;
/*#define pb push_back
#define psi pair<string,int>
#define mp make_pair
int arr[] = {4,7};
//int memo[1000005][2];
std::map<int,std::vector<string> > m;
std::map<string, int>memo;
int dp(int n,int i,string s){
	if(n==0){
		m[s.length()].pb(s);
		return 0;
	}
	int ans=0;
	if(memo.count(s)) return memo[s];
	for (int j = 0; j <2 ; ++j)
	{
		if(n-arr[j]>=0){
			char x = arr[j]+'0';
			ans = 1+dp(n-arr[j],j,s+x);
		}
	}
	return memo[s]=ans;
}*/

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	//memset(memo,-1,sizeof(memo));
	/*int x = dp(n,0,"");
	//int b=0;
	if(m.size()==0) {
		cout<<-1;
		return 0;
	}
	//sort(v.begin(),v.end());
	for (std::map<int, std::vector<string> >::iterator it=m.begin();it!=m.end();it++)
	{
		sort(it->second.begin(),it->second.end());
		cout<<m[it->first][0];
		return 0;
	}*/
	int x = n/7;
	int mx = 9999999;
	int na = 9999999;
	int nb = 9999999;
	for (int i = 1; i < x; ++i)
	{
		int a = (n-i*7)/4;
		if(4*a+7*i==n){
			if(a+i<mx){
				mx = a+i;
				na = a;
				nb = i;
			}
			if(a+i==mx){
				if(i<nb){
					nb = i;
				}
				if(a<na){
					na = a;
				}
			}
		}
	}
	cout<<na<<nb;
	return 0;
}