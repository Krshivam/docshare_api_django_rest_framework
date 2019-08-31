#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[3005];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for (int i = 1; i <=3001; ++i)
	{
		if(!binary_search(arr,arr+n,i)){
			cout<<i;
			return 0;
		}
	}
	//cout<<arr[n-1]+1;
	return 0;
}