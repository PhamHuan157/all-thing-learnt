#include <bits/stdc++.h>
using namespace std;
int n,m,s,t;
vector<int> ke[1001];
bool visited[1001];
// duong di se khac nhau giua dfs va bfs
int parent[1001]; //luu vet

void dfs(int u){
	visited[u] = 1;
	for(int x: ke[u]){
		if(!visited[x]){
			parent[x] = u;
			dfs(x); //hoac bfs
		}
	}
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n>>m>>s>>t;
	for(int i=0; i<m; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	dfs(s);
	if(!visited[t]){
		cout <<-1<<endl;
	}else{
		vector<int> path;
		while(t !=s){
			path.push_back(t);
			t = parent[t]; // truy vet lai cha cua t
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		for(int x:path){
			cout <<x<<" ";
		}
		cout <<endl;
	}
	cin.close();
}

