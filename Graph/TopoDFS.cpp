#include <bits/stdc++.h>
using namespace std;
// topo dfs co huong
vector<int> ke[1001];
bool visited[1001];
int n,m;
vector<int> topo;
void dfs(int u){
	visited[u] = true;
	for(int x: ke[u]){
		if(!visited[x]){
			visited[x] = true;
			dfs(x);
		}
	}
	topo.push_back(u);
}
int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
	}
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	reverse(topo.begin(), topo.end());
	for(int x:topo) cout <<x<<" ";
	cout <<endl;
	cin.close();
}

