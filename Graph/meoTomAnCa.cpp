#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ke[1001];
bool visited[1001];
int gian[1001], ans;

void dfs(int u, int dem){
	visited[u] = true;
	if(dem>m){
		return;
	}
	if(ke[u].size() == 1 and u!=1){
		++ans;
	}
	for(int v: ke[u]){
		if(!visited[v]){
			if(gian[v]){
				dfs(v,dem+1);
			}else dfs(v,0);
		}
	}
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>gian[i];
	for(int i=0; i<n-1; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	ans = 0;
	dfs(1, gian[1]);
	cout <<ans<<endl;
	cin.close();
}

