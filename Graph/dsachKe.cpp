#include <bits/stdc++.h>
using namespace std;
// ds canh sang ds ke (co huong)
vector<int> ke[1001];

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n,m; cin>>n>>m;
	for(int i=0; i<m; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
	}
	for(int i=1; i<=n; i++){
		cout <<i<<" :";
		sort(ke[i].begin(), ke[i].end());
		for(int x: ke[i]){
			cout <<x<<" ";
		}
		cout <<endl;
	}
	cin.close();
}

