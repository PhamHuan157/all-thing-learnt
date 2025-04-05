#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");

	int c,n; cin>>c>>n;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	int res[c+1] ={0};
	res[0] = 1;
	
	for(int i=0; i<n; i++){
		for(int j = c; j>=a[i]; j--){
			if(res[j - a[i]]) res[j] = 1;
		}
	}
	for(int i=c; i>=0; i--){
		if(res[i]){
			cout <<i<<endl;
			return 0;
		}
	}
	/* greedy
	ll total = 0;
	sort(a,a+n, greater<int>());
	for(int i=0; i<n; i++){
		if(total + a[i] <= c){
			total += a[i];
		}
	}
	cout <<total<<endl;
	*/
	

	cin.close();
}


