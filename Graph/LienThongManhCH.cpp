#include <bits/stdc++.h>
using namespace std;
int n,m; 
vector<int> ke[1001];
bool visited[1001];

void dfs(int u){
	visited[u] = 1;
	for(int x: ke[u]){
		if(!visited[x]){
			visited[x] =true;
			dfs(x); //hoac bfs
		}
	}
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
	}
	// duyet trau tim lien thong manh
	for(int i=1; i<=n; i++){
		memset(visited,0,sizeof(visited));
		dfs(i);
		for(int i=1; i<=n; i++){
			if(!visited[i]){
				cout <<"NO\n";
				return 0;
			}
		}
	}
	cout <<"Lien thong\n";

	cin.close();
}

