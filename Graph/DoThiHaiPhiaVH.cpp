#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> ke[1001];
int color[1001];

bool dfs(int u, int par){
	color[u] = 3 - color[par];
	for(int v: ke[u]){
		if(color[v] == 0){
			if(!dfs(v,u)){
				return false;
			}
		}else if(color[v] == color[u]){
			return false;
		}
	}
	return true;
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n>>m;
	bool ok = true;
	for(int i=0; i<m; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	memset(color,0,sizeof(color));
	color[0] = 2;
	for(int i=1; i<=n; i++){
		if(color[i] == 0){
			if(!dfs(i,0)){
				ok = false;
			}
		}
	}
	cout << ok<<endl;
	cin.close();
}

