#include <bits/stdc++.h>
using namespace std;
// cay khung kruskal la 1 do thi vo huong va co n-1 canh (tree) va co trong so tren canh
int n,m;
const int maxn = 1001;
struct edge{
	int u,v;
	int w;
};
vector<edge> canh;
int parent[maxn], size[maxn];

void make_set(){
	for(int i=1; i<=n; i++){
		parent[i] = i;
		size[i] = 1;
	}
}

int find(int u){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = find(parent[u]);
}

bool Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b){
		if(size[a] < size[b]) swap(a,b);
	}else if(a == b) return false; // khong the gop a,b voi nhau
	size[a] += size[b];
	parent[b] = a;
	return true;
}
bool cmp(edge a, edge b){
	return a.w < b.w;
}
void kruskal(){
	// tao cay khung cuc tieu
	vector<edge> mst;
	int d = 0;
	// sort danh sach canh theo chieu dai tang dan
	sort(canh.begin(), canh.end(), cmp);
	// lap
	for(int i=0; i<m; i++){
		if(mst.size() == n-1) break;
		edge e = canh[i];
		if(Union(e.u, e.v)){
			d += e.w;
			mst.push_back(e);
		}
	}
	// tra ve ket qua
	if(mst.size() != n-1){
		cout <<"Do thi khong lien thong"<<endl;
	}else{
		cout <<"MST "<<d<<endl;
		for(auto it: mst) cout <<it.u<<" "<<it.v<<" "<<it.w<<endl;
	}
}
int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x,y,z;
		cin>>x>>y>>z;
		canh.push_back({x,y,z});
	}
	
	make_set();
	kruskal();
	cin.close();
}

