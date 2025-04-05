#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int k; cin>>k;
	string s; cin>>s;
	map<char,int> m;
	for(int i=0; i<s.size(); i++){
		m[s[i]]++;
	}
	priority_queue<int> q;
	for(auto x: m){
		q.push(x.second);
	}
	while(k--){
		int x = q.top();
		q.pop();
		x--;
		q.push(x);
	}
	int res = 0;
	while(q.size()){
		res += q.top()*q.top();
		q.pop();
	}
	cout <<res<<endl;
	
	cin.close();
}

