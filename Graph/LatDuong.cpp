#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;

int n,m, res;
int sz[maxn], parent[maxn];

int find(int u){
	if(u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

int Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return 0;
	if(sz[a] < sz[b]) swap(a,b);
	sz[a] += sz[b];
	res = max(res,sz[a]);
	parent[b] = a;
	return 1;
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin >>n>>m;
	
	for(int i=1; i<=n; i++){
		sz[i] = 1;
		parent[i] = i;
	}
	res = 1;
	int tplt = n;
	for(int i=0; i<m; i++){
		int x,y; cin>>x>>y;
		tplt -= Union(x,y);
		cout <<tplt<<" "<<res<<endl;
	}
	cin.close();
}

