#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100005
ll arr[MAX];

int main(int argc, char const *argv[])
{	
	int n,d;
	cin>>n>>d;
	//ll a[n];
	//memset(arr,1e9+5,sizeof(arr));
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	//sort(a,a+n);
	
	while(i<n){
		b=0;
		cout<<i<<" "<<j;
		if(arr[j]-arr[i]>d){
			int n1 = (j-i)/2;
			cnt += (n1*(n1-1)*(n1-2))/6;
			i++;
		}
		j++;
		if(j>=n) break;
		//j++;
	}
	cout<<cnt;
	return 0;
}