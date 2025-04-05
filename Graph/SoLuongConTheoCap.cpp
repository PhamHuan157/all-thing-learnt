#include <bits/stdc++.h>
using namespace std;
// Tim so cap con d(i,j) = d(1,i) + d(1,j)
int n,m;
vector<int> ke[1001];
int child[1001];

int dfs(int u, int par){
	int cnt = 1;
	for(int v: ke[u]){
		if(v != par){
			cnt += dfs(v,u);			
		}
	}
	child[u] = cnt;
	return cnt;
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n;
	for(int i=0; i<n-1; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	dfs(1,-1);
	int ans = 0;
	for(int i=1; i<=n; i++){
		ans += child[i];
	}
	cout <<ans<<endl;
	cin.close();
}

