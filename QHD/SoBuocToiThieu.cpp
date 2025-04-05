#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// so buoc toi thieu de sap xep lai day 
// van la LIS
/*
13 
143 340 571 845 211 228 274 443 666 594 491 814 24
= 6
*/
int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");

	int n; cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int dp[10001];
	
	for(int i=0; i<n; i++){
		dp[i] = 1;
		for(int j=0; j<i; j++){
			if(a[i] > a[j]){
				dp[i] = max(dp[i], dp[j] +1);
			}
		}
	}
	
	cout <<n - *max_element(dp, dp+n)<<endl;
	cin.close();
}


