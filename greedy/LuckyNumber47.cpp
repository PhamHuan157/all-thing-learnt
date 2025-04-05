#include <bits/stdc++.h>
using namespace std;
// 40 = 4447777
int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n; cin>>n;
	string ans="";
	bool found = false;
	int y = 0;
	for(int i=n/7; i>=1; i--){
		int x = n - 7*i;
		while(x%4==0 and x!=0){
			ans += to_string(4);
			x-=4;
			found = true;
		}
		if(found){
			y = 7*i;
			break;
		}
	}
	while(y%7==0 and y!=0){
		ans+= to_string(7);
		y-=7;
	}
	if(ans.size()){
		cout <<ans<<endl;
	}else cout <<-1<<endl;
	cin.close();
}

