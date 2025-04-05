#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n; cin>>n;
	int a[n];
	for(int&x:a) cin>>x;
	sort(a,a+n);
	long long x1 = 1ll*a[0]*a[1];
	long long x2 = a[n-1]*a[n-2];
	long long x3 = 1ll*a[n-1]*a[n-2]*a[n-3];
	long long x4 = 1ll*a[n-1]*a[0]*a[1];
	cout <<max(max(x1,x2), max(x3,x4))<<endl;
	cin.close();
}

