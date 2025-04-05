#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n; cin>>n;
	int a[n];
	priority_queue<int, vector<int>,greater<int>> q;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		q.push(a[i]);
	}
	int ans = 0;
	while(q.size() >1){
		int t1 = q.top();
		q.pop();
		int t2 = q.top();
		q.pop();
		ans +=t1+t2;
		q.push(t1+t2);
	}
	cout <<ans<<endl;
	cin.close();
}

