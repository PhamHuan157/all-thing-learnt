#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
6 22
39 44 4 59 91 70
47 26 92 33 6 69
*/
int dp[1001][1001];

int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");
	
	int n,v; cin>>n>>v;
	int w[n+1], c[n+1];
	// w[i] khoi luong cua vat thu i
	for(int i=1; i<=n; i++) cin>>w[i];
	// c[i] gia tri cua vat thu i
	for(int i=1; i<=n; i++) cin>>c[i];
	// item i, trong luong j
	for(int i=1; i<=n; i++){
		for(int j=0; j<=v; j++){
			dp[i][j] =  dp[i-1][j];
			if(j >= w[i]){ // dieu kien trong luong j phai lon hon khoi luong w[i]
				dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + c[i]);
			}
		}
	}
	cout <<dp[n][v]<<endl;

	cin.close();
}


