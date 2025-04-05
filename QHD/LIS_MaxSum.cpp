#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//8
//2 12 3 15 3 16 11 4
//= 45
int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");
	
	int n; cin>>n;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	int dp[n+1] ={0};
	for(int i=0; i<n; i++){
		dp[i] = a[i];
		for(int j=0; j<i; j++){
			if(a[i] > a[j]){
				dp[i] = max(dp[i], dp[j] + a[i]);
			}
		}
	}
	
	cout << *max_element(dp,dp+n)<<endl;

	cin.close();
}


