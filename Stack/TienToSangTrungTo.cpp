#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Duyet tu phai sang

void solve(string s){
	stack<string> st;
	for(int i=s.size()-1; i>=0; i--){
		if(isalpha(s[i])) st.push(string(1,s[i]));
		else{
			string s1 = st.top(); st.pop();
			string s2 = st.top(); st.pop();
			string res = "("+s1+s[i]+s2+")";
			st.push(res);
		}
	}
	cout <<st.top()<<endl;
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	
	string s; cin>>s;
	solve(s);


	cin.close();
}

