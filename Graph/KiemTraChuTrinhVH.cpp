#include <bits/stdc++.h>
using namespace std;

int n,m; 
vector<int> ke[1001];
bool visited[1001];

bool dfs(int u, int parent){
	visited[u] = true;
	for(int v: ke[u]){
		if(!visited){
			if(dfs(v,u)) return true;
		}else if(v != parent){
			// dinh v visited nhung v ko phai la cha truc tiep cua u
			return true;
		}
	}
	return false;
	
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
	memset(visited,0, sizeof(visited));
	bool ok =false;
	for(int i=1; i<=n; i++){
		if(!visited[i] and dfs(i,0)){
			ok = true;
			break;
		}
	}
	if(ok){
		cout <<"Yes\n";
	}else cout <<"No\n";
	cin.close();
}

