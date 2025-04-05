#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Hau to ve trung to
// Duyet tu trai sang ab*c+ => ((a*b)+c)

void solve(string s){
	stack<string> st;
	for(int i=0; i<s.size(); i++){
		if(isalpha(s[i])) st.push(string(1,s[i]));
		else{
			string s1 = st.top(); st.pop();
			string s2 = st.top(); st.pop();
			string s3 = "("+s2+s[i]+s1+")";
			st.push(s3);
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

