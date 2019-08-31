#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	if(s.length()==1 || s.length()==2){
		cout<<s;
		return 0;
	}
	int bt=0;
	int i=0;
	
	while(i<s.length())
	{
		if(i>=3 && (s[i]==s[i-1] && s[i]==s[i-2]) || s[i]==s[i-1]){
			
			i++;
		}
		else cout<<s[i],i++;
		//i++;
	}
	return 0;
}