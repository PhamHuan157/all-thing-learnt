#include <bits/stdc++.h>
using namespace std;
struct job{
	int id, profit, deadline;
};

bool cmp(job a, job b){
	return a.profit > b.profit;
}
int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n; cin>>n;
	job a[n];
	for(int i=0; i<n; i++){
		cin>>a[i].id>>a[i].deadline>>a[i].profit;
	}
	sort(a,a+n, cmp);
	int mark[n],sum=0;
	bool used[n];
	memset(used,false,sizeof(used));
	for(int i=0; i<=n-1; i++){
		for(int j=a[i].deadline -1; j>=0; j--){
			if(used[j] == false){
				used[j] = true;
				mark[j] = i;
				sum += a[i].profit;
				break;
			}
		}
	}
	int res = 0;
	for(int i=0; i<n; i++){
		if(used[i]){
			++res;
		}
	}
	cout <<res<<" "<<sum<<endl;
	cin.close();
}

