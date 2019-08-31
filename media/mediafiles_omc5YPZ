#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		ll n,f;
		cin>>n>>f;
		std::map<ll,int>arr;
		ll mx = f;
		for (int i = 0; i < n; ++i)
		{
			ll d;
			cin>>d;
			mx = max(mx,d);
			arr[d]+=1;
		}
		ll ans=0;
		int trck=0;
		ll idx = f;
		while(idx<=mx){
			for (map<ll, int>::iterator it=arr.begin();it!=arr.end();it++)
			{
				ll t1=it->first;
				if(t1%idx==0 && arr[t1/idx]){
					ll x = arr[t1];
					ll y= arr[t1/idx];
					ans += x*y;
				}
				if(trck==0){
					ll x = arr[t1];
					ans+=x*(x-1)/2;
				}
			}
			trck=1;
			idx*=f;
		}
		cout<<ans<<endl;
	}
	return 0;
}