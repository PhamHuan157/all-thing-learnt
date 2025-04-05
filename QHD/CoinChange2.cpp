#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// so cach rieng biet de tao ra tien can doi
const int mod = 1e9+7;

int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");

	int n,s; cin>>n>>s;
	int a[n], dp[s+1];
	for(int i=0; i<n; i++) cin>>a[i];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int i=1; i<=s; i++){
		for(int c: a){
			if( i >=c)
			dp[i] = (dp[i]+dp[i-c])%mod;
		}
	}
	cout <<dp[s]<<endl;


	cin.close();
}


