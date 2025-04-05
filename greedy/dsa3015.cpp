#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n,s,m; cin>>n>>s>>m;
	int remain_day = 0;
	if(n/m < 1){
		cout <<-1<<endl;
	}else{
		while(s>0){
			remain_day++;
			s -= n/m;
		}
		cout <<remain_day<<endl;
	}
	
	cin.close();
}

