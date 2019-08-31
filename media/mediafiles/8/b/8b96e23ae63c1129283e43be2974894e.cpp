#include<bits/stdc++.h>
using namespace std;
set<int>s;
int arr[70];
std::vector<string> v;
int cnvert(string x){
	stringstream lx(x);
	int y=0;
	lx>>y;
	return y;
}

void findQuasi(string x,int i,int n){
	if(i==n){
		return ;
	}
	s.insert(cnvert(x));
	findQuasi(x+'0',i+1,n);
	findQuasi(x+'1',i+1,n);
}


int dp(int i,int n,int val,string t){
	if(val==0){
		//cout<<t<<endl;
		return 0;
	}
	int ans = 99999;
	for (int j = i; j < n; ++j)
	{
		if(val-arr[j]>=0){
			//cout<<arr[j]<<" "<<val<<" "<<t<<endl;
			char f = j+'0';
			ans = min(ans,1+dp(j,n,val-arr[j],t+f));
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int val;
	cin>>val;
	findQuasi("",0,7);
	//cout<<s.size();
	set<int> :: iterator it;
	int i=0;
	for (it=s.begin();it!=s.end();it++)
	{
		if(*it!=0){
			arr[i] = *it;
			i++;
		}
		
	}
	//string g="";
	int h = dp(0,s.size()-1,val,"")
	cout<<h<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		if(v[i].length()==h){
			for (int i = 0; i < v[i].length(); ++i)
			{
				cout<<arr[i-'0']<<" ";
			}
			return 0;
		}
	}
	return 0;
}