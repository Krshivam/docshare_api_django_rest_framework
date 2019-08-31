#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int main(int argc, char const *argv[])
{
	int d,sumtime;
	cin>>d>>sumtime;
	pii arr[d];
	int need = 0;
	for (int i = 0; i < d; ++i)
	{
		cin>>arr[i].first>>arr[i].second;
		need+=arr[i].first;
	}
	int i=0;
	if(sumtime-need<0){
		cout<<"NO"<<endl;
		return 0;
	}
		//cout<<"YES"<<endl;
		while(sumtime-need>0 && i<d){
			int mn = min(sumtime-need,arr[i].second-arr[i].first);
			arr[i].first+=mn;
			need+=mn;
			i++;
		}
	
	if(sumtime-need>0) cout<<"NO";
	else{
		cout<<"YES"<<endl;
		for (int i = 0; i < d; ++i)
	{
		cout<<arr[i].first<<" ";
	}
	}
	
	return 0;
}