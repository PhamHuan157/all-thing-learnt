#include <bits/stdc++.h>
using namespace std;
// ma tran trong so sang ma tran ke
int a[1001][1001];
int visited[1001][1001];
int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n; cin>>n;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>a[i][j];
			if(a[i][j] !=0 and visited[i][j] == 0 and visited[j][i] ==0){
				cout <<i<<" "<<j<<" "<<a[i][j]<<endl;
				visited[j][i] = visited[i][j] = 1;
			}
		}
	}
	cin.close();
}

