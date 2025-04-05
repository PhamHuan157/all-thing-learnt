#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	string s; cin>>s;
	vector<int> vitri;
	for(int i=0; i<s.size(); i++){
		if(s[i] == '['){
			vitri.push_back(i);
		}
	}
	int cnt = 0, trace = 0, res =0;
	for(int i=0; i<s.size(); i++){
		if(s[i] =='['){
			++cnt;
			++trace;
		}else if(s[i] ==']') --cnt;
		if(cnt <0){
			res += vitri[trace] - i;
			swap(s[i], s[vitri[trace]]);
			cnt = 1;
			++trace;
		}
	}
	cout <<res<<endl;
	cin.close();
}

