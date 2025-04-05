#include <bits/stdc++.h>
using namespace std;
int n,m;
char a[1001][1001];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
bool visited[1001][1001];

void dfs(int i,int j){
	visited[i][j] = true;
	for(int k=0; k<4; k++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >=1 and i1<=n and j1 >=1 and j1<=m and a[i1][j1] =='x' and !visited[i1][j1]){
			dfs(i1,j1);
		}
	}
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>a[i][j];
		}
	}
	memset(visited,0,sizeof(visited));
	int cnt = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i][j] =='x' and !visited[i][j]){
				dfs(i,j);
				cnt++;
			}
		}
	}
	cout <<cnt<<endl;
	cin.close();
}

