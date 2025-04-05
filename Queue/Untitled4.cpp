#include <bits/stdc++.h>
using namespace std;


int bfs(int s, int t){
	set<int> se;
	queue<pair<int,int>> q;
	q.push({s,0});
	while(q.size()){
		pair<int,int> top = q.front();
		q.pop();
		if(top.first == t) return top.second;
		if(top.first-1 == t or top.first*2 == t) return top.second +1;
		int x = top.first;
		if(x>1 and !se.count(x-1)){
			q.push({x-1,top.second+1});
			se.insert(x-1);
		}
		if(!se.count(x*2)){
			q.push({x*2, top.second+1});
			se.insert(x*2);
		}
	}
}
int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	
	int t; cin>>t;
	while(t--){
		int s,t; cin>>s>>t;
		cout <<bfs(s,t)<<endl;
	}

	cin.close();
}

