#include <bits/stdc++.h>
using namespace std;

int n;
int parent[1001], size[1001];

void make_set(){
	for(int i=1; i<=n; i++){
		parent[i] = i;
		size[i] = 1;
	}
}

int find(int v){
	if(v == parent[v]){
		return v;
	}
	return parent[v] = find(parent[v]); // path compression, tim lai cha cua no
	//return find(parent[v]);  // chua path compression, chua toi uu
}

void Union(int a,int b){
	a = find(a);
	b = find(b);
	if(a != b){
		if(size[a] < size[b]){
			swap(a,b);
		}
	}
	parent[b] = a;
	size[a] += size[b];
	
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>n;
	while(1){
		int x; cin>>x;
		if(x == 0) break;
		else if(x == 1) make_set();
		else if(x == 2){
			int v; cin>>v;
			find(v);
		}else if(x == 3){
			int a,b; cin>>a>>b;
			Union(a,b);
		}
	}
	cin.close();
}

