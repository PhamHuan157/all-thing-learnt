#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/* tong phan tu khong lien ke
7
314 514 148 451 896 589 296
 1706
*/
int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");

	int n; cin>>n;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	ll sum[n+1] ={0};
	sum[1] = a[1];	
	for(int i = 2; i<=n; i++){
		sum[i] = max(sum[i-1], sum[i-2] + a[i]);
	}
	cout <<sum[n]<<endl;

	cin.close();
}


