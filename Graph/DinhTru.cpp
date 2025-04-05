#include <bits/stdc++.h>
using namespace std;
//O(V*(V+E))
int n,m;
vector<int> ke[1001];
bool visited[1001];

void dfs(int u){
	visited[u] = true;
	for(int v: ke[u]){
		if(!visited[v]){
			dfs(v);	
		}
	}
}

void dinhtru(){
	int ans = 0;
	int tplt = 0;
	memset(visited,0, sizeof(visited));
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			++tplt;
			dfs(i);
		}
	}
	
	for(int i=1; i<=n; i++){
		// loai bo i khoi do thi
		memset(visited, false, sizeof(visited));
		visited[i] = 1;
		int dem = 0;
		for(int j=1; j<=n; j++){
			if(!visited[j]){
				++dem;
				dfs(j);
			}
		}
		if(dem > tplt){
			cout <<i<<" ";
			ans++;
		}
	}
	cout <<endl;
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
	}
	dinhtru();
	cin.close();
}

