#include <bits/stdc++.h>
using namespace std;
// Dung cho do thi vo huong
int n,m; 
vector<int> ke[1001];
bool visited[1001];

void dfs(int u){
	visited[u] = 1;
	for(int x: ke[u]){
		if(!visited[x]){
			visited[x] =true;
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
	// dem thanh phan lien thong
	int cnt = 0;
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			cnt++;
			dfs(i);
		}
	}
	cout <<cnt<<endl;
	// check do thi co lien thong hay khong
//	dfs(1);
//	for(int i=1; i<=n; i++){
//		if(!visited[i]){
//			cout <<"No"<<endl;
//			return 0;
//		}
//	}
//	cout <<"Yes\n";
	cin.close();
}

