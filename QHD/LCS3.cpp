#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//AGLEHHGE
//GLGHLALB
//DDLBLEHGD
//= 2
int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");
	
	string s1,s2,s3; cin>>s1>>s2>>s3;
	int n= s1.size(), m = s2.size(), t = s3.size();
	int dp[n+1][m+1][t+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n; i++){
		for(int j=1; j<=m; j++){
			for(int k = 1; k<=t; k++){
				dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
				
				if(s1[i-1] == s2[j-1] and s2[j-1] == s3[k-1]){
					dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-1]+1);
				}
			}
		}
	}

	cout <<dp[n][m][t]<<endl;

	cin.close();
}


