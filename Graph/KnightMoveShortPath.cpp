#include <bits/stdc++.h>
using namespace std;
int n,s,t,u,v;
int a[1001][1001];
int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};
int d[1001][1001];

bool bfs(int i, int j){
	d[i][j] = 0;
	queue<pair<int,int>> q;
	q.push({i,j});
	while(q.size()){
		pair<int,int> x = q.front();
		q.pop();
		if(x.first == u and x.second == v) return true;
		for(int k=0; k<8; k++){
			int i1 = x.first + dx[k];
			int j1 = x.second + dy[k];
			if(i1>=1 and j1>=1 and i1<=n and j1<=n and a[i1][j1] == 1){
				q.push({i1,j1});
				a[i1][j1] = 0;
				d[i1][j1] = d[i][j]+1;
			}
		}
	}
	return false;
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n>>s>>t>>u>>v;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>a[i][j];
		}
	}
	if(bfs(s,t)){
		cout <<d[u][v]<<endl;
	}else cout <<-1<<endl;
	cin.close();
}

