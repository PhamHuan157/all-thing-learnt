#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second < b.second;
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n; cin>>n;
	pair<int,int> a[n];
	cout <<n<<endl;
	for(int i=0; i<n; i++){
		cin>>a[i].first>>a[i].second;
	}
	sort(a,a+n, cmp);
	int end_time = a[0].second;
	int amount = 1;
	for(int i=1; i<n; i++){
		if(end_time < a[i].first){
			++amount;
			end_time = a[i].second;
		}
	}
	cout <<amount<<endl;
	cin.close();
}

