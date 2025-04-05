#include <bits/stdc++.h>
using namespace std;

struct canh{
	int x,y,w;
};
int n,m;
const int maxn = 1001;
vector<pair<int,int>> ke[maxn];
bool used[maxn];

void prim(int u){
	vector<canh> mst;
	int d = 0;
	used[u] = true;
	while(mst.size() <n -1){
		// e = (x,y) : canh ngan nhat co x thuoc V va V(MST)
		int min_w = INT_MAX;
		int X,Y;
		for(int i=1; i<=n; i++){
			//neu dinh i thuoc V(mst)
			if(used[i] == true){
				// duyet danh sach ke
				for(pair<int,int> c: ke[i]){
					int j = c.first;
					int trongso = c.second;
					if(!used[j] and trongso < min_w){
						min_w = trongso;
						X = j, Y = i;
						
					}
				}
				
			}
		}
		mst.push_back({X,Y,min_w});
		d += min_w;
		used[X] = true; // cho dinh X vao V(mst), loai X khoi tap V
		
	}
	cout <<d<<endl;
	for(canh e: mst){
		cout <<e.x<<" "<<e.y<<" "<<e.w<<endl;
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
	prim(1);
	cin.close();
}

