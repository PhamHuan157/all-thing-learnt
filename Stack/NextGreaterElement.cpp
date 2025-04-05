#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");

	int n; cin>>n;
	int a[n], b[n];
	for(int i=0; i<n; i++) cin>>a[i];
	stack<int> st;
	for(int i=0; i<n; i++){
		if(st.empty()) st.push(i);
		else{
			while(!st.empty() and a[st.top()] < a[i]){
				b[st.top()] = a[i];
				st.pop();
			}
			st.push(i);
		}
	}
	while(!st.empty()){
		b[st.top()] = -1;
		st.pop();
	}
	for(int x:b) cout <<x<<" ";
	cin.close();
}

