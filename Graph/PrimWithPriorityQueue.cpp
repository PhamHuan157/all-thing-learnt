#include <bits/stdc++.h>
using namespace std;

struct canh{
	int x,y,w;
};
int n,m;
const int maxn = 1001;
vector<pair<int,int>> ke[maxn];
bool used[maxn];
int parent[maxn], d[maxn]; //dung tim cay khung

void prim(int u){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	vector<canh>mst;
	int res = 0;
	q.push({0,u});
	while(q.size()){
		pair<int,int> top = q.top(); q.pop();
		int dinh = top.second, trongso = top.first;
		if(used[dinh] == true) continue;
		res += trongso;
		used[dinh] = true;
		if(u != dinh){ // tim cay khung
			mst.push_back({dinh, parent[dinh], trongso});
		}
		for(auto it: ke[dinh]){
			int y =it.first, w = it.second;
			if(!used[y] and w < d[y]){  // and w < d[y] tim cay khung
				d[y] = w; // tim cay khung
				q.push({w,y});
				parent[y] = dinh; // tim cay khung
			}
		}
	}
	cout <<res<<endl;
	for(auto it: mst){
		cout <<it.x<<" "<<it.y<<" "<<it.w<<endl;
	}
}
int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x,y,z; cin>>x>>y>>z;
		ke[x].push_back({y,z});
		ke[y].push_back({x,z});
	}
	memset(used,0,sizeof(used));
	// dung tim cay khung
	for(int i=1; i<=n; i++){
		d[i] = INT_MAX;
	}
	prim(1);
	cin.close();
}
