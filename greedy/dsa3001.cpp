#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	int n; cin>>n;
	int a[10] ={1000,500,200,100,50,20,10,5,2,1};
	int res = 0;
	for(int i=0; i<10; i++){
		res += n / a[i];
		n %= a[i];
	}
	cout <<res<<endl;
	cin.close();
}

