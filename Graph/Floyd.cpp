#include <bits/stdc++.h>
using namespace std;

int n,m,q;
long long d[501][501];

void Floyd(){
	for(int k=1; k<=n; k++){
		for(int i=1;i<=n; i++){
			for(int j=1; j<=n; j++){
				if ((d[i][k] != LLONG_MAX) && (d[k][j] != LLONG_MAX)){
                	d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
			}
		}
	}

}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	
	memset(d,0,sizeof(d));
	cin>>n>>m>>q;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i == j) d[i][j] = 0;
			else d[i][j] = LLONG_MAX;
		}
	}
	
	for(int i=0;i<m; i++){
		long long x,y,z; cin>>x>>y>>z;
		d[x][y] = d[y][x] = min(d[x][y],(long long)z);
	}
	Floyd();
	while(q--){
		int x,y; cin>>x>>y;
		if(d[x][y] == LLONG_MAX) cout <<-1<<endl;
		else cout <<d[x][y]<<endl;
	}
	cin.close();
}

