#include <bits/stdc++.h>
using namespace std;
// cay co n dinh, n-1 canh

int n,m; 
vector<int> ke[1001];
int height[1001];
bool visited[1001];

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	height[u] = 0;
	while(q.size()){
		int v = q.front();
		q.pop();
		for(int x: ke[v]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
				height[x] =height[v] +1;
			}
		}
	}
}

void dfs(int u, int parent){
	visited[u] = true;
	height[u] = height[parent]+1;
	for(int x: ke[u]){
		if(!visited[x]){
			dfs(x,u);
		}
	}
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n;
	for(int i=0; i<n; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	memset(height,0,sizeof(height));
	height[0]=-1;
	bfs(1);
//	dfs(1,0);
	for(int i=1; i<=n; i++){
		cout <<height[i]<<" ";
	}
	cin.close();
}

