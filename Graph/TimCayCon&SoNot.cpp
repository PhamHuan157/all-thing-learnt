#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// cay co n-1 canh, n dinh

vector<int> ke[10001];
bool visited[10001];
int h[10001],c[10001], parent[10001],n;

int dfs(int u){
	h[u] = h[parent[u]]+1;
	c[u] = 1;
	visited[u] = true;
	for(int v: ke[u]){
		if(!visited[v]){
			parent[v] = u;
			c[u] += dfs(v); // cong so not con cua cay con
			// goc v vao cay con goc u
		}
	}
	return c[u];
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");

	cin>>n;
	for(int i=1; i<=n; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	dfs(1);
	for(int i=1; i<=n; i++){
		cout <<h[i]<<" "<<c[i]<<endl;
	}
	/*
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			if(dfs(i)){
				cout <<"YES\n"; return 0;
			}
		}
	}
	cout <<"NO\n";
*/
	cin.close();
}

