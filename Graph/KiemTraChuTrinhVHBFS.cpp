#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ke[1001];
bool visited[1001];
int parent[1001];

bool bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(q.size()){
		int v = q.front();
		q.pop();
		for(int x: ke[v]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
				parent[x] = v;
			}else if(x != parent[v]){
				return true;
			}
		}
	}
	return false;
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
	bool ok = false;
	memset(visited,0,sizeof(visited));
	for(int i=1; i<=n; i++){
		if(!visited[i] and bfs(i)){
			ok = true;
			break;
		}
	}
	cout <<ok<<endl;
	
	cin.close();
}

