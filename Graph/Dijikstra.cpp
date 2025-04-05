#include <bits/stdc++.h>
using namespace std;
// Dijikstra 
// cac canh khong duoc la so am, co the ap dung cho VH va CH
// S: source
// (E+V)*LogV
// Khong co duong di thi in ra INT_MAX
const int maxn = 1001;
int n,m, d[maxn];
vector<pair<int,int>> ke[maxn];

void dijikstra(int s){
	for(int i=1; i<=n; i++){
		d[i] = INT_MAX;
	}
	d[s] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push({0,s});
	while(q.size()){
		pair<int,int> top = q.top(); q.pop();
		int u = top.second; // dinh
		int len = top.first;  // chi phi duong di
		if(len > d[u]) continue;
		for(auto it: ke[u]){
			int v = it.first;
			int w = it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] +w;
				cout <<v<<" "<<d[v]<<endl;
				q.push({d[v],v});
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(d[i] != INT_MAX){
			cout <<d[i]<<" ";
		}
	}
	cout <<endl;
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x,y,z; cin>>x>>y>>z;
		ke[x].push_back({y,z});
	}
	
	dijikstra(3);	
	
	cin.close();
}

