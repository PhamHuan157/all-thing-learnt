#include <bits/stdc++.h>
using namespace std;
int n,m; 
vector<int> ke[1001];
bool visited[1001];
vector<vector<int>> lt;
vector<int> cd;

void dfs(int u){
	cd.push_back(u);
	cout <<u<<" ";
	visited[u] = 1;
	for(int x: ke[u]){
		if(!visited[x]){
			visited[x] = true;
			dfs(x); //hoac bfs
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
	// liet ke cac thanh phan lien thong 
	int cnt = 0;
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			cnt++;
			dfs(i);
			cout <<endl;
			lt.push_back(cd);
			cd.clear();
		}
	}
	cout <<cnt<<endl;
	for(int i=0; i<lt.size(); i++){
		for(int x:lt[i]){
			cout <<x<<" ";
		}
		cout <<endl;
	}
	cin.close();
}

