#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//8
//7 8 8 19 3 6 2 15
//= 49
int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");

	int n; cin>>n;
	int a[n];
	for(int i =0; i<n; i++) cin>>a[i];
	int dp1[n+1]={0}, dp2[n+1]={0};
	
	for(int i=0; i<n; i++){
		dp1[i] = a[i];
		for(int j=0; j<i; j++){
			if(a[i] > a[j]){
				dp1[i] = max(dp1[i], dp1[j] +a[i]);
			}
		}
	}
	for(int i=n-1; i>=0; i--){
		dp2[i] = a[i];
		for(int j=n; j>i; j--){
			if(a[i] > a[j]){
				dp2[i] = max(dp2[i], dp2[j] + a[i]);
			}
		}
	}

	int res = 0;
	for(int i=0; i<n;i++){
		cout <<dp1[i]<<" "<<dp2[i]<<" "<<a[i]<<endl;
		res = max(res, dp1[i]+dp2[i]- a[i]);
	}
	cout <<res<<endl;
	cin.close();
}


