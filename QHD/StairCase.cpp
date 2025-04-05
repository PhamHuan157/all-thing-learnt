#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 7 3 => 44
int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");

	int n,k; cin>>n>>k;
	int mod = 1e9+7;
	ll res[n+1];
	memset(res,0,sizeof(res));
	res[0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<= min(k,i); j++){
			res[i] = (res[i] + res[i-j])%mod;
		}
	}
	cout <<res[n]<<endl;

	cin.close();
}


