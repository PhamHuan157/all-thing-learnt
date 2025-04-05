#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");

	int n; cin>>n;
	int a[n], dp[10];
	for(int i=0; i<n; i++){
		cin>>a[i];
		dp[i] = 1;
	}
	
	for(int i=0; i<n; i++){
		for(int j = 0; j<i; j++){
			if(a[i] > a[j]){
				dp[i] = max(dp[i], dp[j]+1);                                                                                                                            
			}
		}
	}
	
	cout << *max_element(dp,dp+n)<<endl;
	

	cin.close();
}


