#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
int arr[3001];
std::vector<int> v;
void soe(){
	for (int i = 2; i <=3000 ; ++i)
	{
		if(i%2==0) arr[i] = 0;
		else arr[i] = 1;
	}

	for(int i=3;i*i<=3000;i+=2){
		if(arr[i]){
			for (int j = i*i; j <=3000 ; j+=i)
			{
				arr[j] = 0;
			}
		}
	}
	arr[2] = 1;
	for (int i = 2; i <=3000; ++i)
	{
		if(arr[i]) v.pb(i);
	}
}

bool isprime(int n){
	int cnt=0;
	std::map<int, int>h;
	for (int i = 2; i*i<=n; ++i)
	{
		if(arr[i] && n%i==0){
			while(n%i==0) n/=i;
			h[i] = 1;

		}
	}
	if(n>=2) h[n]=1;
	if(h.size()==2) return true;
	return false;
}

int main(int argc, char const *argv[])
{
	soe();
	//cout<<sizeof(arr)/sizeof(int);
	int n;
	cin>>n;
	//cout<<isprime(2)<<" "<<isprime(6)<<" "<<isprime(9);
	int cnt= 0;
	for (int i = 4; i <=n; ++i)
	{
		if(isprime(i)) cnt++;
	}
	cout<<cnt;

	return 0;
}