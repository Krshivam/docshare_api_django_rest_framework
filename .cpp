#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int cntm = 0;
	int cntmx = 0;
	if(n%7==0) cntm+=n/7 *2 ,cntmx+=n/7 *2;
	else if(n%7==6) cntm+=n/7*2 + 1 ,cntmx+= n/7*2 + 2;
	else cntm+= n/7 *2 ,cntmx+= n/7 *2 + 2;
	cout<<cntm<<cntmx;
	return 0;
}