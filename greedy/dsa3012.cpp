#include <bits/stdc++.h>
using namespace std;

long long cuberoot(long long x) {
    if (x < 0) {
        return -pow(-x, 1.0/3.0);
    } else if (x > 0) {
        return pow(x, 1.0/3.0);
    } else {
        return 0;
    }
 }
int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n; cin>>n;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	for(int x:a) cout <<x<<" ";
	cout <<endl;
	for(int i=1; i<n; i++){
		a[i] = a[i-1] + a[i];
	}
	for(int x: a) cout <<x<<" ";
	cout <<endl;
	cin.close();
}

