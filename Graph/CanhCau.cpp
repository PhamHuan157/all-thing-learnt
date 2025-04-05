#include <bits/stdc++.h>
using namespace std;
//O(E*(V+E))
int n,m;
vector<int> ke[1001];
bool visited[1001];
vector<pair<int,int>> dscanh;

void dfs(int u){
	visited[u] = true;
	for(int v: ke[u]){
		if(!visited[v]){
			dfs(v);	
		}
	}
}

void dfs2(int u, int s,int t){
	visited[u] = true;
	for(int x: ke[u]){
		if((u==s and t == x) or ( u== t and s == x)) continue;
		if(!visited[x]){
			dfs2(x,s,t);
		}
	}
}
void CanhCau(){
	int ans = 0;
	int tplt = 0;
	memset(visited,0,sizeof(visited));
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			dfs(i);
			tplt++;
		}
	}
	
	for(auto it: dscanh){
		int x = it.first;
		int y = it.second;
		// loai bo canh x,y khoi do thi
		memset(visited,0,sizeof(visited));
		int dem = 0;
		for(int j = 1; j<=n; j++){
			if(!visited[j]){
				dfs2(j,x,y);
				++dem;
			}
		}
		if(dem > tplt){
			cout <<x<<" "<<y<<endl;
			++ans;
		}
	}
	cout <<ans<<endl;
}
int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
		dscanh.push_back({x,y});
	}
	CanhCau();
	cin.close();
}

