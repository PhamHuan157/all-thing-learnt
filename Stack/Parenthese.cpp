#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");

	stack<char> st;
	string s; cin>>s;
	for(int i=0; i<s.size(); i++){
		if(s[i] =='(') st.push(s[i]);
		else{
			if(st.empty()){
				cout <<"NO\n";
				return 0;
			}else{
				if(st.top() == '('){
					st.pop();
				}
			}
		}
	}
	if(st.empty()) cout<<"YES\n";
	else cout <<"NO\n";

	cin.close();
}

