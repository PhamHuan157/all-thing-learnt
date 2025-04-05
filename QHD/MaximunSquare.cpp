#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");

	int n,m; cin>>n>>m;
	int a[n+1][m+1];
	memset(a,0,sizeof(a));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>a[i][j];
		}
	}
	
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	int ans = 0;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(i == 1 or j == 1) dp[i][j] = a[i][j];
			else{
				if(a[i][j]){
					dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) +1;
				}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout <<ans<<endl;
	cin.close();
}


