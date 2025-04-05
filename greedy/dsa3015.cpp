#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n,s,m; cin>>n>>s>>m;
	int lt = s*m;
	int day = s - s/7;
	if(lt > day*n){
		cout <<-1<<endl;
	}else{
		for(int i=1; i<=day; i++){
			if(lt < n*i){
				cout <<i<<endl;
				break;
			}
		}	
	}
	cin.close();
}

