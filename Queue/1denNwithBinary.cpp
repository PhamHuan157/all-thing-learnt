#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> res;

void init(){
	queue<string> q;
	q.push("1");
	while(res.size() <=10000){
		string top = q.front(); q.pop();
		string a = top+"0", b = top+"1";
		res.push_back(top);
		q.push(a);
		q.push(b);
		
	}	
	
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");

	init(); 
	int n; cin>>n;
	for(int i=0; i<n; i++){
		cout <<res[i]<<" ";
	}
	

	cin.close();
}

