#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// co the tao ra duoc tong s neu chi dung moi phan tu 1 lan
int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");

	int n,s; cin>>n>>s;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	vector<bool> dp(s+1, false);
	// luon luon tao dc tong = 0 (true)
	dp[0] = true;
	for(int i=0; i<n; i++){
		// duyet tu s ve a[i] de tranh dung 1 phan tu 2 lan
		for(int j = s; j>=a[i]; j--){
			// neu duyet tu a[i] -> s, thi
			// khi j = a[i] thi 2x - 2x = 0, tong = true => 4x = true
			// khi do 2x duoc su dung nhieu hon 1 lan, etc
			if(dp[j - a[i]]) dp[j] = true;
		}
	}
	if(dp[s]) cout <<1<<endl;
	else cout <<0<<endl;

	cin.close();
}


