#include <bits/stdc++.h>
using namespace std;

int main(){
	long long X, K, D;
	cin >> X >> K >> D;
	long long num = X / D;
	if(abs(num) <= K){
		K -= abs(num);
		X %= D;
	}
	else{
		if(X < 0){
			X += K * D;
			K = 0;
		}
		else{
			X -= K * D;
			K = 0;
		}
	}
	//cout << X << ":" << K << endl;
	if(K % 2){
		if(X < 0) X += D;
		else X -= D;
	}
	cout << abs(X) << endl;
}
