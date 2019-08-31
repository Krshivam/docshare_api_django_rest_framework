#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll arr[100005];
ll sm[100005];


int n,m,k;
ll sum(int idx){
	ll s=0;
	while(idx>0){
		s+=arr[idx];
		idx -= (idx&-idx);
	}
	return s;
}
void update(int l,int r,int val,int b){
	while(l<=r){
		if(!b) arr[l]+=val;
		else sm[l]+=1;
		l+=(l&-l);
	}
}


int main(int argc, char const *argv[])
{
	
	//int n,m,k;
	cin>>n>>m>>k;
	arr[0] = 0;
	memset(sm,0,sizeof(sm));
	for (int i = 1; i <= n; ++i)
	{
		cin>>arr[i];
	}
	while(m--){
		int l,r,val;
		cin>>l>>r>>val;
		update(l,r,val,0);
		update(l,r,val,1);
	}
	while(k--){
		int l,r;
		cin>>l>>r;
	}
	return 0;
}