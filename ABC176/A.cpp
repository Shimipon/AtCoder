#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, X, T;
	cin >> N >> X >> T;
	int kai = N / X;
	if(N % X > 0)kai++;
	cout << kai * T << endl;
}
