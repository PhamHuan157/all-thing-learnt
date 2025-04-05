#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");
	
	int n,m; cin>>n>>m;
	int a[n], dp[m+1];
	for(int i=0; i<n; i++) cin>>a[i];
	dp[0] = 0;
	for(int i=1; i<=m; i++){
		dp[i] =1e9;
		for(int c: a){
			if(i >= c){
				dp[i] = min(dp[i], dp[i - c]+1);
			}
		}
	}
	if(dp[m] == 1e9) cout <<"Cant\n";
	else cout <<dp[m]<<endl;

	cin.close();
}


