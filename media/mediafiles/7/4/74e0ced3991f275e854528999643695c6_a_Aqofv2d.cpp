#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[4];
	cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
	sort(arr,arr+4);
	if(arr[0]+arr[1]>arr[2] || arr[1]+arr[2]>arr[3]){
		cout<<"TRIANGLE";
	}
	else if(arr[0]+arr[1]==arr[2] || arr[1]+arr[2]==arr[3]) cout<<"SEGMENT";
	else cout<<"IMPOSSIBLE";
		//1 3 5 9
	//1 2 3 4
	return 0;
}