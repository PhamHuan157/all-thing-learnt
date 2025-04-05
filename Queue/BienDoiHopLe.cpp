#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int,int>;

int s,t;
bool prime[10000001];

void sieve(){
	memset(prime,1,sizeof(prime));
	prime[0] = prime[1] = 0;
	for(int i=2; i<=sqrt(10000); i++){
		if(prime[i]){
			for(int j=i*i; j<=10000; j+=i){
				prime[i] = false;
			}
		}
	}
}

int bfs(int s, int t){
	queue<pi> q;
	q.push({s,0});
	bool used[10001];
	memset(used,0,sizeof(used));
	used[s] = true;
	while(q.size()){
		pi tmp = q.front(); q.pop();
		int num = tmp.first, x= num;
		if(num == t) return tmp.second;
		vector<int> digit;
		while(x){
			digit.push_back(x%10);
			x/=10;
		}
		reverse(digit.begin(), digit.end());
		for(int i=0; i<4; i++){
			for(int j=0; j<=9; j++){
				if(i==0 and j==0) continue;
				if(digit[i] != j){
					int new_num = 0;
					for(int k=0; k<4; k++){
						if(i!=k){
							new_num = new_num*10 + digit[k];
						}else new_num = new_num*10 +j;
					}
					if(prime[new_num] and !used[new_num]){
						q.push({new_num,tmp.second+1});
						used[new_num] = 1;
					}
				}
			}
		}
	}	
	return -1;
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");

	cin>>s>>t;
	sieve();
	cout <<bfs(s,t);
	cin.close();
}

