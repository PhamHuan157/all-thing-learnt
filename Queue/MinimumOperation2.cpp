#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int,int>;

int n;

int bfs(int n){
	queue<pi> q;
	q.push({n,0});
	unordered_map<int,int> mp;
	mp[n] = 1;
	while(q.size()){
		pi tmp = q.front();
		q.pop();
		if(tmp.first == 1) return tmp.second;
		for(int i=2; i<=sqrt(n); i++){
			if(tmp.first%i == 0){
				int m = max(i,tmp.first/i);
				if(mp[m] == 0){
					q.push({m,tmp.second+1});
					mp[m] =1;
				}
			}
		}
		if(mp[tmp.first- 1] == 0){
			q.push({tmp.first-1, tmp.second+1});
			mp[tmp.first-1] = 1;
		}
	}
	return 0;
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	
	cin>>n;
	cout <<bfs(n);


	cin.close();
}

