#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ke[1001];
bool visited[1001];
vector<int> pos;
int cnt[1001],k;

void dfs(int u){
	visited[u] = true;
	cnt[u]++;
	for(int v: ke[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>k>>n>>m;
	for(int i=0; i<k; i++){
		int x; cin>>x;
		pos.push_back(x);
	}
	for(int i=0; i<m; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
	}
	
	for(int x: pos){
		memset(visited,0,sizeof(visited));
		dfs(x);
	}
	int ans = 0;
	for(int i=1; i<=n; i++){
		if(cnt[i] == k){
			ans++;
		}
	}
	cout <<ans<<endl;
	cin.close();
}

