#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> res;

void bfs(){
	queue<int> q;
	for(int i=1; i<6; i++) q.push(i);
	while(1){
		int t = q.front(); q.pop();
		res.push_back(t);
		if(t>100000) break;
		int used[6] = {0};
		int temp = t;
		while(t){
			used[t%10] = 1;
			t/=10;
		}
		for(int i=0; i<6; i++){
			if(!used[i]){
				q.push(tmp*10+i);
			}
		}
		
	}
}


int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");

	bfs();

	cin.close();
}

