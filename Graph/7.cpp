#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n,m; cin>>n>>m;
	int a[101][101];
	while(m--){
		int x,y; cin>>x>>y;
		a[x][y] = a[y][x] = 1;
	}
	for(int i=1; i<=5; i++){
		for(int j = 1; j<=5; j++){
			cout <<a[i][j]<<" ";
		}
		cout <<endl;
	}
	cin.close();
}

