#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	ifstream cin;
	cin.open("C:/devC/random_test/input.txt");

	int n; cin>>n;
	int res[n+1] ={0};
	res[0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=6; j++){
			if(i >=j){
				res[i] = (res[i] + res[i-j])%mod;
			}
		}
	}
	cout <<res[n]<<endl;
	
	cin.close();
}


