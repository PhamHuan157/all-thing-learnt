#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y){
	return x.second < y.second;
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n; cin>>n;
	int a[n],b[n];
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<n; i++) cin>>b[i];
	pair<int, int> p[n];
	for(int i=0; i<n; i++){
		p[i].first = a[i];
		p[i].second = b[i];
	}
	sort(p,p+n, cmp);
	int end_time = p[0].second;
	int ans = 1;
	for(int i=1; i<n; i++){
		if(end_time < p[i].first){
			ans++;
			end_time = p[i].second;
		}
	}
	cout <<ans<<endl;
	cin.close();
}

