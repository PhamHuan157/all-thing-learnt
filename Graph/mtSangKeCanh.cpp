#include <bits/stdc++.h>
using namespace std;
// ma tran ke sang ds ke va ds canh
int used[1001][1001];
int main(){
	ifstream cin;
	memset(used,0,sizeof(used));
	cin.open("C:/devC/input.txt");
	int n; cin>>n;
	int total = 0;
	int a[n+1][n+1];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>a[i][j];
			total += a[i][j];
		}
	}
	vector<pair<int,int>> p;
	vector<int> ke[n+1];
	// co the xet nua tam giac tren
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
//			if(a[i][j] !=0 and used[i][j] ==0 and used[j][i] == 0){
//				used[i][j] = used[j][i] =1;
//				p.push_back({j,i});
//			}
			if(a[i][j] !=0){
				ke[i].push_back(j);
				p.push_back({i,j});
				ke[j].push_back(i);
			}
		}
	}
	sort(p.begin(), p.end());
	for(auto x:p){
		cout <<x.first<<" "<<x.second<<endl;
	}
	for(int i=1; i<=n; i++){
		cout <<i<<" :";
		for(int x: ke[i]){
			cout <<x<<" ";
		}
		cout <<endl;
	}
	cin.close();
}

