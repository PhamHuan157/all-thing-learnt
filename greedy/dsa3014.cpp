#include <bits/stdc++.h>
using namespace std;

bool check(long long n){
	long long can = cbrt(n);
	if(can*can*can != n){
		return false;
	}
	return true;
}
long long res = 0;
int x[100],n;
string s;
void ql(int i){
	for(int j=0; j<=1; j++){
		x[i] = j;
		if(i==n-1){
			long long temp = 0;
			for(int i=0; i<n; i++){
				if(x[i]){
					temp = temp*10 + (s[i]-'0');
				}
			}
			if(check(temp) and temp > res){
				res = temp;
			}
		}else ql(i+1);
	}
}
int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>s;
	n = s.size();
	res = 0;
	memset(x,0,sizeof(x));
	ql(0);
	if(res!=0){
		cout <<res<<endl;
	}else cout <<-1<<endl;	
	cin.close();
}

