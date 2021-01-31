#include <bits/stdc++.h>
using namespace std;

int main(){
	long long A = 1;
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		long long S;
		cin >> S;
		if(S == 0){
			A = 0;
			break;
		}
		if(A == -1) continue;
		long long B = A;
		A *= S;
		if(A > 1000000000000000000 || B > LLONG_MAX / S){
			A = -1;
		}
	}
	cout << A << endl;
}
