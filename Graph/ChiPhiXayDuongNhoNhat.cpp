#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
struct canh{
	int x,y,w;
};

int n,m;
int sz[maxn], parent[maxn];
vector<canh> edge;

int find(int u){
	if(u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

bool Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return false;
	if(sz[a] < sz[b]) swap(a,b);
	sz[a] += sz[b];
	parent[b] = a;
	return true;
}

bool cmp(canh a, canh b){
	return a.w < b.w;
}
void kruskal(){
	sort(edge.begin(), edge.end(), cmp);
	long long ans = 0;
	int cnt = 0;
	for(int i=0; i<m; i++){
		if(cnt == n -1) break;
		if(Union(edge[i].x, edge[i].y)){
			++cnt;
			ans += edge[i].w;
		}
	}
	if(cnt != n -1) cout <<"IMPOSSIBLE\n";
	else cout <<ans<<endl;
}
int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin >>n>>m;
	for(int i=0; i<m; i++){
		int x,y,z; cin>>x>>x>>z;
		edge.push_back({x,y,z});
	}
	for(int i=1; i<=n; i++){
		sz[i] = 1;
		parent[i] = i;
	}
	
	kruskal();
	cin.close();
}

