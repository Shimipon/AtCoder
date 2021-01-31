#include <bits/stdc++.h>
using namespace std;


long long pow(long long A, long long P){
	long long a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	long long adash = a * a;
	if(p % 2) return pow(adash, p / 2) * a;
	else return pow(adash, p / 2);
}

int main(){
	long long N;
	cin >> N;
	long long M = pow(2,N);
	long long A[M];
	int B[M];
	for(int i=0;i<M;i++){
		cin >> A[i];
		B[i] = i;
	}
	for(int i=1;i<=N-1;i++){
		// cout << i << endl;
		long long c = pow(2,i);
		for(int j=0;j<M;j++){
			if(j % c == 0){
				B[j] = j;
			}
			else{
				if(A[j] > A[j-1]){
					B[j] = j;
				}
				else{
					A[j] = A[j-1];
					B[j] = B[j-1];
				}
			}
			// cout << j << ":" << B[j] << endl;
		}
	}
	if(A[M-1] > A[M / 2 - 1])cout << B[M / 2 - 1] + 1 << endl;
	else cout << B[M-1] + 1 << endl;
}
