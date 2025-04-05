#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n; cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans = 0;
	for(int i=n-1; i>=0; i--){
		ans += a[i]*i;
	}
	cout <<ans;
	cin.close();
}

