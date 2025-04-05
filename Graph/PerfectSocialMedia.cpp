#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ke[1001];
bool visited[1001];
vector<int> tplt;
int cnt;

void dfs(int u){
	++cnt;
	visited[u] = true;
	for(int v: ke[u]){
		if(!visited[v]){
			dfs(v);
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
		ke[y].push_back(x);
	}
	memset(visited,0,sizeof(visited));
	for(int i=1; i<=n; i++){
		memset(visited,0,sizeof(visited));
		if(!visited[i]){
			tplt.clear();
			cnt = 0;
			dfs(i);
			for(int x: tplt){
				if(ke[x].size() != cnt-1){
					cout <<"NO\n";
					return 0;
				}
			}
		}
	}
	cout <<"YES\n";
	cin.close();
}

