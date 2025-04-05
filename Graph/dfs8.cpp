#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> ke[1001];
bool visited[1001];

void dfs(int u){
	visited[u] = true;
	cout <<u<<" ";
	for(int x: ke[u]){
		if(!visited[x]){
			visited[x] = true;
			dfs(x);
		}
	}
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n>>m>>k;
	for(int i =0; i<m; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	for(int i=1; i<=n; i++){
		sort(ke[i].begin(), ke[i].end());
	}
	memset(visited,0,sizeof(visited));
	dfs(k);
	cin.close();
}

