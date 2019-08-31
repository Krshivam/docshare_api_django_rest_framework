#include<bits/stdc++.h>
using namespace std;

std::vector<int>z_f(string s){
	int n = s.length();
	std::vector<int>z(n,0);
	int l,r;
	for (int i = 1,l=0,r=0;i < n; ++i)
	{
		if(i<=r) z[i] = min(r-i+1,z[i-l]);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
		if(r<i+z[i]-1) l = i,r = i+z[i]-1;
	}
	return z;
}

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	std::vector<int> v = z_f(s);
	std::map<int, int> m;
	int ans=0;
	for (int i = 0; i < s.length(); ++i)
	{
		cout<<v[i]<<" ";
		if(v[i]>0) m[v[i]]++;
	}
	for (std::map<int, int>::iterator it=m.begin();it!=m.end();it++)
	{
		if(it->first>ans && it->second>=2) ans = it->first;
	}
	if(!ans) cout<<"Just a legend";
	else{
		for (int i = 0; i < ans; ++i)
		{
			cout<<s[i];
		}
	}
	
	return 0;
}