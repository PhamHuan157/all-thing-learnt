#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	string s1; cin>>s1;
	string s2; cin>>s2;
	string dupmx = "";
	string dupm = "";
	for(int i=0; i<s1.size(); i++){
		if(s1[i] =='6'){
			dupmx +='5';
		}else dupmx +=s1[i];
	}
	for(int i=0; i<s2.size(); i++){
		if(s2[i] =='6'){
			dupm +='5';
		}else dupm +=s2[i];
	}
	cout << stoll(dupmx) +stoll(dupm)<<endl;
	dupmx.clear();dupm.clear();
	for(int i=0; i<s1.size(); i++){
		if(s1[i] =='5'){
			dupmx +='6';
		}else dupmx +=s1[i];
	}
	for(int i=0; i<s2.size(); i++){
		if(s2[i] =='5'){
			dupm +='6';
		}else dupm +=s2[i];
	}
	cout <<stoll(dupmx) +stoll(dupm)<<endl;
	cin.close();
}

