#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
5 5
1 0 31 5 25 
28 26 32 46 7
26 40 36 13 16
7 26 14 6 11
42 45 11 10 21
= 28
*/

int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");

	int n,m; cin>>n>>m;
	int a[n+1][m+1];
	memset(a,0,sizeof(a));
	for(int i =1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>a[i][j];
		}
	}
	
	for(int i =1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(i == 1){
				a[i][j] = a[i][j-1] + a[i][j];
			}else if(j == 1){
				a[i][j] += a[i-1][j];
			}else{
				a[i][j] += max({a[i-1][j], a[i][j-1],a[i-1][j-1]});
			}
		}
	} 
	cout <<a[n][m]<<endl;

	cin.close();
}


