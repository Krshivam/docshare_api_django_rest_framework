#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(int argc, char const *argv[])
{
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	set<ll> s;
	s.insert(arr[0]);
	for (int i = 1; i < n; ++i)
	{
		set<ll>::iterator it;
		it = s.find(arr[i-1]/k);
		if(it!=s.end()) s.insert(arr[i]);
	}
	cout<<s.size();
	return 0;
}