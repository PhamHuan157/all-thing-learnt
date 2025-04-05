#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n; cin>>n;
	string res ="";
	int y = 0;
	bool found = false;
	for(int i=n/7; i>=0; i--){
		int x = n - 7*i;
		while(x%4 == 0 and x >=4){
			x -=4;
			res += to_string(4);
			found  =true;
			y = 7*i;
		}
	}
	while(y%7 ==0 and y>=7){
		res += to_string(7);
		y -=7;
	}
	if(!found){
		cout <<-1<<endl;
	}else cout <<res<<endl;
	
	cin.close();
}

