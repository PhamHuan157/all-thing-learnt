#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// duyet tu trai sang ab+cd-* => *+ab-cd

void solve(string s){
	stack<string> st;
	for(int i=0; i<s.size(); i++){
		if(isalpha(s[i])) st.push(string(1,s[i]));
		else{
			string s1 = st.top(); st.pop();
			string s2 = st.top(); st.pop();
			string s3 = s[i]+s2+s1;
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

