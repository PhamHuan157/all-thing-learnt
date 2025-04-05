#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// so cach bieu dien so tien ma khong xet den thu tu
// vd 6 = 4+2 or 2+4 van la 1 cach 
const int mod = 1e9+7;

int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");

	int n,s; cin>>n>>s;
	int a[n], dp[s+1];
	for(int i=0; i<n; i++) cin>>a[i];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int c: a){
		for(int i=c; i<=s; i++){
			dp[i] += dp[i-c];
		}
	}
	cout <<dp[s]<<endl;


	cin.close();
}


