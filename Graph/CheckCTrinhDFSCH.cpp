#include <bits/stdc++.h>
using namespace std;

int n,m; 
vector<int> ke[1001];
int color[1001];

bool dfs(int u, int parent){
	color[u] = 1;
	for(int v: ke[u]){
		if(color[v] == 0){
			if(dfs(v,u)) return true;
		}else if(color[v] == 1){
			return true;
		}
	}
	color[u] = 2;
	
}
int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
	}
	memset(color,0,sizeof(color));
	bool ok =false;
	for(int i=1; i<=n; i++){
		if(color[i] == 0 and dfs(i,0)){
			ok = true;
			break;
		}
	}
	if(ok){
		cout <<"Yes\n";
	}else cout <<"No\n";
	cin.close();
}

