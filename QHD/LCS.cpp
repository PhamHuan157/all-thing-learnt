#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
index starts at 1
dp[i][j] <=> dp[0][j] = dp[i][0] = 0
* s[i] = t[j]
<=> dp[i][j] = dp[i-1][j-1]+1;

*s[i] != t[j]
<=> dp[i][j] = max(dp[i-1][j], dp[i][j-1])

ZHFTDFHF
TFISHROV
 = 3
*/
int dp[1001][1001];
int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");
	
	string s1,s2;
	cin>>s1>>s2;
	

	int n = s1.size(), m = s2.size();
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // truong hop gia su
			if(s1[i-1] == s2[j-1]){ // truong hop neu co s = t
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
			}
		}
	}
	
	cout <<dp[n][m]<<endl;
	
	cin.close();
}


