#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ke[1001];
bool visited[1001];
int indegree[1001];
// trong truong hop co huong va co chu trinh thi thuat toan kahn va dfs ko the duyet duoc moi dinh
void kahn(){
	queue<int> q;
	for(int i=1; i<=n; i++){
		if(!indegree[i]){
			q.push(i);
		}
	}
	while(q.size()){
		int u = q.front();
		q.pop();
		cout <<u<<" ";
		for(int v:ke[u]){
			indegree[v]--;
			if(indegree[v]==0){
				q.push(v);
			}
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
		indegree[y]++;
	}
	memset(visited,0,sizeof(visited));
	kahn();
	cin.close();
}

