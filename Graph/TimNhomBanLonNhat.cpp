#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ke[1001];
bool visited[1001];
int cnt;

void dfs(int u){
	visited[u] = true;
	cnt++;
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
	int mx = 0;
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			mx = max(mx, cnt);
			cnt = 0;
			dfs(i);
		}
	}
	cout <<mx<<endl;
	cin.close();
}

