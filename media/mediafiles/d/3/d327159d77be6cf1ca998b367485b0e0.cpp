#include<bits/stdc++.h>
using namespace std;
#define pii p

int main(int argc, char const *argv[])
{
	string src,dest;
	cin>>src>>dest;
	if(src[0]-97+src[1]-'0'==dest[0]-97+dest[1]-'0'){
		cout<<abs(src[1]-dest[1]);
	}
	if(src[0]-97==dest[0]-97){
		cout<<abs(src[1]-dest[1]);
	}
	if(src[1]-'0'==dest[1]-'0'){
		cout<<abs(src[0]-dest[0]);
	}
	else {
		
	}
	return 0;
}