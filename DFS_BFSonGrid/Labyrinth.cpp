#include <bits/stdc++.h>
using namespace std;
int n,m;
char a[1001][1001];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool visited[1001][1001];
bool ok  = false;
string ans="";
int d[1001][1001];

// tim duong di thong thuong
void dfs(int i, int j){
	visited[i][j] = true;
	if(a[i][j] == 'B'){
		cout <<"YES there is a way between A and B\n";
		cout <<ans.size()<<endl;
		cout <<ans<<endl;
		ok = true;
		return;
	}
	for(int k=0; k<4; k++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(!ok and i1>=1 and j1>=1 and i1<=n and j1<=m and !visited[i1][j1] and (a[i1][j1] =='.' or a[i1][j1]=='B')){
			if(k == 0) ans += 'U';
			else if(k==1) ans += 'R';
			else if(k==2) ans +='D';
			else ans+='L';
			visited[i1][j1] = true;
			dfs(i1,j1);
			ans.pop_back();
			visited[i1][j1] = false;
		}
	}
}

// tim duong di ngan nhat
void bfs(int i, int j){
	queue<pair<int,int>>q;
	q.push({i,j});
	d[i][j] = 0;
	visited[i][j] = true;
	while(q.size()){
		pair<int,int> u = q.front();
		q.pop();
		for(int k = 0; k<4; k++){
			int i1 = dx[k] + u.first;
			int j1 = dy[k] + u.second;
			if(i1>=1 and j1>=1 and i1<=n and j1<=m and !visited[i1][j1] and (a[i1][j1] =='.' or a[i1][j1]=='B')){
				q.push({i1,j1});
				d[i1][j1] = d[u.first][u.second]+1;
				if(a[i1][j1] == 'B'){
					ok = true;
					cout <<"YES\n";
					return;
				}
				visited[i1][j1] = true;
			}
		}
	}
}
int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n>>m;
	int u1,v1,u2,v2;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>a[i][j];
			if(a[i][j] =='A'){
				u1 = i, u2 = j;
			}else if(a[i][j] =='B'){
				v1=i, v2=j;
			}
		}
	}
	bfs(u1,u2);
	if(!d[v1][v2]){
		cout<<"NO\n";
	}else cout <<d[v1][v2]<<endl;
//	if(!ok) cout <<"NO\n";
	cin.close();
}

