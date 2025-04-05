#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> ke[1001];
bool visited[1001];

void dfs(int u){
	cout <<u<<" ";
	visited[u] = true;
	// duyet danh sach ke cua u
	for(int x: ke[u]){
		if(!visited[x]){
			dfs(x);
		}
	}
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin >>n>>m;
	for(int i=0; i<m; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	memset(visited,0,sizeof(visited));
	dfs(1);
	cin.close();
}

