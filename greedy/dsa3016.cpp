#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int s,n; cin>>s>>n;
	s--;
	int res[n];
	if(s>n*9){
		cout <<-1<<endl;
	}else{
		for(int i=n-1; i>=1; i--){
			if(s>=9){
				res[i] = 9;
				s -=9;
			}else{
				res[i] = s;
				s=0;
			}
		}
		res[0] = s+1;
		for(int x: res) cout <<x;
	}
	cout <<endl;
	cin.close();
}

