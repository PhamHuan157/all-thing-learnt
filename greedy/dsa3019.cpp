#include <bits/stdc++.h>
using namespace std;
long long tu,mau;

void ql(long long tu, long long mau){
	if(mau%tu == 0){
		cout <<1<<"/"<<	mau/tu<<endl;
		return;
	}
	long long x = mau/tu+1;
	cout <<1<<"/"<<x<<" + ";
	long long tumoi = tu*x - mau;
	long long maumoi = mau*x;
	ql(tumoi, maumoi);
}

int main(){
	ifstream cin;
	cin.open("C:/devC/input.txt");
	cin>>tu>>mau;
	ql(tu,mau);	
	cin.close();
}

