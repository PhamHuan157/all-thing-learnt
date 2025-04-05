#include <bits/stdc++.h>
using namespace std;
int n,m;
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int a[1001][1001];
bool visited[1001][1001];

void dfs(int i, int j){
	visited[i][j] = true;
	for(int k=0; k<8; k++){
		int i1 = i +dx[k];
		int j1 = j +dy[k];
		if(i1>=1 and j1>=1 and i1<=n and j1<=m and a[i1][j1] ==1 and !visited[i1][j1]){
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
	int cnt = 0;
	memset(visited,0,sizeof(visited));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(!visited[i][j] and a[i][j] != 0){
				dfs(i,j);
				++cnt;
			}
		}
	}
	cout <<cnt<<endl;
	cin.close();
}
