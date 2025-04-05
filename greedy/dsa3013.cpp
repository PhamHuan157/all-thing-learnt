#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second > b.second;
}
int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n; cin>>n;
	string s; cin>>s;
	map<char, int> m;
	for(int x:s) m[x]++;
	sort(m.begin(), m.end(), cmp);
	int used[s.size()];
	for(int i = 0; i<s.size(); i++){
		if(used[i]){
			continue;
		}else{
			char temp = m[i];
			int idx  =i;
			while(m[temp]){
				used[idx]++;
				idx+=d;
				m[temp]--;
				if(idx >=s.size()){
					cout <<-1<<endl;
					break;
				}	
			}
		}
		
	}
	cin.close();
}

