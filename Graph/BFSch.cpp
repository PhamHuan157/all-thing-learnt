#include <bits/stdc++.h>
using namespace std;

int n,m;
queue<int> q;
vector<int> ke[1001];
bool visited[1001];

void bfs(int u){
	visited[u] = true;
	q.push(u);
	while(q.size()){
		int v = q.front();
		q.pop();
		cout <<v<<" ";
		for(int x: ke[v]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
			}
			
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
	}
	memset(visited,0,sizeof(visited));
	bfs(1);
	cin.close();
}

