#include<bits/stdc++.h>
using namespace std;

int matrix2[1001][1001],matrix5[1001][1001],dp[1001][1001],arr[1001][1001];

int solve(int x,int n){
	int cnt=0;
	while(x%n==0 && x>0){
		x/=n;
		cnt++;
	}
	return cnt;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	//cout<<"Hello";
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j<=n; ++j)
		{
			cin>>arr[i][j];
			if(arr[i][j]=0) arr[i][j]=10;
		}
	}
	//cout<<"Hello";
	for (int i = 1; i < n+1; ++i)
	{
		for(int j=1;j<n+1;j++){
			matrix2[i][j] = solve(arr[i][j],2);
			matrix5[i][j] = solve(arr[i][j],5);
			dp[i][j]=0;
		}
		//cout<<"Hello";
	}

	for(int i=1;i<=n;i++) dp[1][i] = dp[1][i-1]+matrix2[1][i];
	for(int i=1;i<=n;i++) dp[i][1] =dp[i-1][i]+matrix2[i][1];
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			dp[i][j] = min(dp[i-1][j],dp[i][j-1])+matrix2[i][j];
		}
	}
	int r=n,c=n;
	string s1="";
	while(r>1 || c>1){
		if(r>1&&c>1){
			if(dp[r-1][c]>=dp[r][c-1]){
				s1+="R";
				c--;
			}
			else s1+="D",r--;
		}
		else if(r>1){
			s1+="D",r--;
		}
		else if(c>1){
			s1+="R";
			c--;
		}
	}
	int cnt2 = dp[n][n];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++) dp[1][i] = dp[1][i-1]+matrix5[1][i];
	for(int i=1;i<=n;i++) dp[i][1] =dp[i-1][i]+matrix5[i][1];
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			dp[i][j] = min(dp[i-1][j],dp[i][j-1])+matrix5[i][j];
		}
	}
	r=n,c=n;
	string s2="";
	while(r>1 || c>1){
		if(r>1&&c>1){
			if(dp[r-1][c]>=dp[r][c-1]){
				s2+="R";
				c--;
			}
			else s2+="D",r--;
		}
		else if(r>1){
			s2+="D",r--;
		}
		else if(c>1){
			s2+="R";
			c--;
		}
	}
	int cnt5 = dp[n][n];
	if(cnt5>cnt2){
		cout<<cnt2<<endl;
		reverse(s1.begin(),s1.end());
		cout<<s1;
	}
	else{
		cout<<cnt5<<endl;
		reverse(s2.begin(), s2.end());
		cout<<s2;
	}
	return 0;
}