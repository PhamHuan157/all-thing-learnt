#include <bits/stdc++.h>
using namespace std;
//Bellman_Ford: Giong Dijikstra nhung co the ap tren do thi co trong so am
// tru truong hop do thi co chu trinh am (negative cycle, tong cac duong trong chu trinh bi am)
// Bellman-Ford thuong duoc dung de kiem tra chu trinh am
// O(V*E)

struct edge{
	int x,y,w;
};
int n,m;
vector<edge> dscanh;
int d[1000001];

void Bellman_Ford(int s){
	for(int i=1; i<=n; i++){
		d[i] = INT_MAX;
	}
	d[s] = 0;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<m; j++){
			edge temp = dscanh[j];
			int x =temp.x, y = temp.y, w = temp.w;
			if(d[x] < INT_MAX){
				d[y] = min(d[y], d[x] + w);
			}
		}
	}
	for(int i=1; i<=n; i++) cout <<d[i]<<" ";
	cout <<endl;
}
int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");

	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x,y,z; cin>>x>>y>>z;
		dscanh.push_back({x,y,z});
	}
	
	Bellman_Ford(1);
	

	cin.close();
}

