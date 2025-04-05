#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n,k; cin>>n>>k;
	k = min(k,n-k);
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long x =0;
	long long y =0;
	for(int i=0; i<k; i++){
		x += a[i];
	}
	int idx = 0;
	for(int i =k; i<n; i++){
		y += a[i];
	}
	cout << abs(x-y)<<endl;
	cin.close();
}

