#include <bits/stdc++.h>
using namespace std;
const int MOD = 100000007;
int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n; cin>>n;
	int a[n];
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i=0; i<n; i++){
		cin>>a[i];
		q.push(a[i]);
	}
	long long ans = 0;
	while(q.size()!=1){
		int x = q.top();
		q.pop();
		int y = q.top();
		q.pop();
		ans += x%MOD +y%MOD;
		ans %=MOD;
		q.push(x+y);
	}
	cout <<ans<<endl;
	cin.close();
}

