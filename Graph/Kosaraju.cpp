#include <bits/stdc++.h>
using namespace std;
// dung cho do thi co huong
int n,m;
vector<int> ke[100001];
bool visited[100001];
stack<int> topo;
vector<int> rv[1000001]; // danh sach ke dao nguoc
vector<int> travel;

void dfs(int u){
	visited[u] = true;
	for(int v: ke[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
	topo.push(u);
}

void dfs2(int u){
	visited[u] = true;
	for(int x: rv[u]){
		if(!visited[x]){
			dfs2(x);
		}
	}
}
int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
		rv[y].push_back(x);
	}
	memset(visited,0,sizeof(visited));
	
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	memset(visited,0,sizeof(visited));
	int cnt = 0;
	while(topo.size()){
		int v = topo.top();
		topo.pop();
		if(!visited[v]){
			travel.push_back(v);
			++cnt;
			dfs2(v);
		}
	}
	if(cnt == 1) cout <<"YES\n";
	else{
		cout <<"NO\n";
		cout <<travel[1]<<" "<<travel[0]<<endl;
	}
	cin.close();
}

