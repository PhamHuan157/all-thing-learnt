#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Duyet tu trai sang
// Chuyen trung to thanh hau to
// do uu tien cua char o dinh stack ma lon hon phan tu
// chuan bi dua vao thi cho phan tu o dinh stack vao res
// gap dau '(' thi phai pop cho toi khi gap toi dau ')'

int uuTien(char c){
	if(c == '^') return 3;
	else if(c == '*' or c == '/') return 2;
	else if(c == '+' or c == '-') return 1;
	else return 0;
}

void solve(string s){
	string res="";
	stack<char> st;
	for(int i=0; i<s.size(); i++){
		if(isalpha(s[i])){
			res+=s[i];
		}else if(s[i] =='(') st.push(s[i]);
		else if (s[i] ==')'){
			while(!st.empty() and st.top() != '('){
				res+=st.top(); st.pop();
			}
			st.pop(); // xoa not dau mo ngoac
		}else{
			// khi gap toan tu
			while(!st.empty() and uuTien(s[i]) <= uuTien(st.top())){
				res+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(st.size()){
		res+=st.top();
		st.pop();
	}
	cout <<res<<endl;
}




int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");

	string s; cin>>s;
	solve(s);

	cin.close();
}

