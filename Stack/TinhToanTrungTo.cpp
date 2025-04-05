#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//6*3+2-(6-4/2)
// Duyet tu phai sang
int pre(char c){
	if(c == '*' or c=='/') return 2;
	else if(c=='+' or c=='-') return 1;
	else return 0;
}

ll tinhToan(ll a, ll b, char c){
	if(c =='+') return a+b;
	else if(c=='-') return a-b;
	else if(c=='*') return a*b;
	else if(c=='/') return a/b;
}

void solve(string s){
	stack<char> st1;
	stack<ll> st2;
	for(int i=0; i<s.size(); i++){
		if(s[i] == '(') st1.push(s[i]);
		else if(isdigit(s[i])){
			ll tmp = 0;
			// Doc cho den khi gap toan tu 6 60 600
			while(i<s.size() and isdigit(s[i])){
				tmp =tmp*10 +s[i] -'0';
				i++;
			}
			st2.push(tmp);
			--i;
		}else if(s[i] == ')'){
			//thuc hien tinh toan torng dau ()
			while(!st1.empty() and st1.top() != '('){
				ll o1 = st2.top(); st2.pop();
				ll o2 = st2.top(); st2.pop();
				st2.push(tinhToan(o2,o1,st1.top()));
				st1.pop();
			}
			st1.pop();
		}else{
			// toan tu
			while(!st1.empty() and pre(st1.top()) >= pre(s[i])){
				ll o1 =st2.top(); st2.pop();
				ll o2 =st2.top(); st2.pop();
				st2.push(tinhToan(o2,o1,st1.top()));
				st1.pop();
			}
			st1.push(s[i]);
		}
	}
	// thuc hien tinh toan trong cac toan tu con lai
	while(!st1.empty()){
		ll o1 =st2.top(); st2.pop();
		ll o2 =st2.top(); st2.pop();
		st2.push(tinhToan(o2,o1,st1.top()));
		st1.pop();
	}
	cout <<st2.top()<<endl;
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");

	string s; cin>>s;
	solve(s);

	cin.close();
}

