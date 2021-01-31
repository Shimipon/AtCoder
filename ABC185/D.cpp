#include <bits/stdc++.h>
using namespace std;
long long Euclidean(long long A, long long B){
	long long C = 0;
	if(A == B)return A;
	if(A > B){
		C = A % B;
		if(C == 0) return B;
		else return Euclidean(B, C);
	}
	else{
		C = B % A;
		if(C == 0) return A;
		else return Euclidean(A, C);
	}
}

int main(){
	long long N, M;
	cin >> N >> M;
	long long A[M + 2];
	A[0] = 0;
	for(int i=0;i<M;i++){
		cin >> A[i+1];
	}
	sort(A, A + sizeof(A) / sizeof(A[0]));
	A[M+1] = N+1;
	long long B[M+1];
	for(int i=0;i<M+1;i++){
		B[i] = A[i+1] - A[i] - 1;
		// cout << i << ":" << B[i] << endl;
	}
	long long Min = N;
	for(int i=0;i<M+1;i++){
		if(B[i] == 0)continue;
		Min = min(B[i], Min);
	}
	long long ans = 0;
	for(int i=0;i<M+1;i++){
		ans += B[i] / Min;
		if(B[i] % Min > 0)ans++;
	}
	cout << ans << endl;
}
