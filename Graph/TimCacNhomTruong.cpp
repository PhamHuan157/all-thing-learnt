#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ke[1001];
bool visited[1001];
int cnt;
vector<int> tplt;

void dfs(int u){
	visited[u] = true;
	tplt.push_back(u);
	for(int v: ke[u]){
		if(!visited[v]){
			dfs(v);
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
	memset(visited,0,sizeof(visited));
	for(int i=1; i<=n; i++){
		sort(ke[i].begin(), ke[i].end());
	}
	vector<int> nhom;
	for(int i=1; i<=n; i++){
		if(!visited[i]){
//			nhom.push_back(i);
//			dfs(i);
			tplt.clear();
			dfs(i);
			sort(tplt.begin(), tplt.end());
			int res = i, max_val = 0;
			for(int x: tplt){
				if(ke[x].size()>max_val){
					max_val = ke[x].size();
					res = x;
				}
			}
			nhom.push_back(res);
		}
	}
	sort(nhom.begin(), nhom.end());
	for(int x: nhom) cout <<x<<" ";
	cin.close();
}

