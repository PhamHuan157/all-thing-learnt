#include <bits/stdc++.h>
using namespace std;
// ds ke sang ds canh
vector<int> ke[1001];

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n; cin>>n;
	vector<pair<int,int>> canh;
	cin.ignore();
	for(int i=1; i<=n; i++){
		string s; getline(cin,s);
		stringstream ss(s);
		string so;
		while(ss>>so){
			canh.push_back({i, stoll(so)});
		}
	}
	sort(canh.begin(), canh.end());
	for(auto x: canh){
		cout <<x.first<<" "<<x.second<<endl;
	}
	cin.close();
}

