#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n; cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a,a+n);
	string s1="";
	string s2="";
	for(int i=0; i<n; i++){
		if(i%2==0){
			s1+=to_string(a[i]);
		}else s2 += to_string(a[i]);
	}
	int x = stoi(s1);
	int y = stoi(s2);
	cout <<x+y<<endl;
	cin.close();
}

