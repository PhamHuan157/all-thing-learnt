#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	string s; cin>>s;
	map<char, int> m;
	int max_frequency = 0;
	for(int i=0; i<s.size(); i++){
		m[s[i]]++;
	}
	for(auto x: m){
		max_frequency = max(max_frequency, x.second);
	}
	int remains = s.size() - max_frequency;
	if(max_frequency - 1 <= remains){
		cout <<1<<endl;
	}else cout <<-1<<endl;
	cin.close();
}

