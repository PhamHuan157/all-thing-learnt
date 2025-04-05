#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("test_input.txt");
	int n,	m; cin>>n>>m;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	int mini = 0;
	int idx = n-1;
	int total = 0;
	sort(a,a+n);
	while(total != m){
		if(total + a[idx] <= m){
			total +=a[idx];
			mini ++;
		}else idx--;
	}
	cout <<mini<<endl;
	cin.close();
	
}
