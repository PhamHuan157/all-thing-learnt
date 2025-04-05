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
	vector<int> b(a,a+n);
	sort(b.begin(),b.end());
	bool ok = true;
	for(int i=0; i<n; i++){
		if(a[i] != b[i] and b[i] != a[n - i -1]){
			cout <<"No"<<endl;
			ok = false;
			break;
		}
	}
	if(ok){
		cout <<"Yes"<<endl;
	}
	cin.close();
}

