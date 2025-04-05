#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");

	int n; cin>>n;
	int a[7];
	for(int i=0; i<6; i++){
		a[i] = i+1;
	}
	int dp[n+1]={0};
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=6; j++){
			if(j - i <=6) cnt++;
		}
	}

	cin.close();
}


