#include <bits/stdc++.h>
using namespace std;

const int maxn  = 100001;
vector<int> ke[maxn];
int color[maxn], parent;

bool dfs(int u, int parent){
	color[u] = 1;
	for(int v: ke[u]){
		if(!color[u]){
			if(dfs(v,u));
		}else if(color[v] == 1) return false;
	}
	return true;
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");

	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
	}
	
	for(int x: topo){
		cout <<pupils[x]<<" ";
	}
	cout <<endl;
	cin.close();
}

