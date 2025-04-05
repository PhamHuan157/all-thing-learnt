#include <bits/stdc++.h>
using namespace std;
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
	vector<int> road;
	int ans = -1;
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			++ans;
			road.push_back(i);
			dfs(i);
		}
	}
	cout <<ans<<endl;
	for(int i=0; i<road.size()-1; i++){
		cout <<road[i]<<" "<<road[i+1]<<endl;
	}
	
	cin.close();
}

