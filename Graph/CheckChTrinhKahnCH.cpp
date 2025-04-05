#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ke[1001];
bool visited[1001];
int indegree[1001];
// chu trinh co huong
bool kahn(){
	queue<int> q;
	for(int i=1; i<=n; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	int cnt = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		++cnt;
		for(int v:ke[u]){
			indegree[v]--;
			if(indegree[v]==0){
				q.push(v);
			}
		}
	}
	if(cnt == n){
		return 0;
	}else return 1;
}
int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n>>m;
	memset(indegree,0,sizeof(indegree));
	for(int i=0; i<m; i++){
		int x,y; cin>>x>>y;
		ke[x].push_back(y);
		indegree[y]++;
	}
	memset(visited,0,sizeof(visited));
	cout << kahn()<<endl;
	cin.close();
}

