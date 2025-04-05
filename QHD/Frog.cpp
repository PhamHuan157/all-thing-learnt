#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//5 => 13
int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");

	int n; cin>>n;
	int dp[n+2] ={0};
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	int mod = 1e9 +7;
	for(int i=4; i<=n; i++){
		dp[i] += dp[i-1] + dp[i-2] + dp[i-3];
		dp[i]%=mod;
	}
	cout <<dp[n]<<endl;

	cin.close();
}


