#include <bits/stdc++.h>
using namespace std;

int main(){
	long long N, M, T;
	cin >> N >> M >> T;
	long long A[M + 2], B[M + 2];
	A[0] = 0, B[0] = 0;
	A[M+1] = T, B[M+1] = T;
	for(int i=0;i<M;i++){
		cin >> A[i+1] >> B[i+1];
	}
	long long V = N;
	long long c = 0;
	string ans = "No";
	for(int i=0;i<=M;i++){
		N -= A[i+1] - B[i];
		if(N <= 0)break;
		N += B[i+1] - A[i+1];
		if(N > V)N = V;
	}
	if(N > 0)ans = "Yes";
	cout << ans << endl;
}
