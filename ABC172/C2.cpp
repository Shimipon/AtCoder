#include <bits/stdc++.h>
using namespace std;
int main(){
	long N, M, K;
	cin >> N >> M >> K;
	long A[N], B[M];
	for(long i=0;i<N;i++){
		cin >> A[i];
	}
	for(long i=0;i<M;i++){
		cin >> B[i];
	}
	long sumA[N+1];
	sumA[0] = 0;
	long li = 0;
	for(int i=1;i<N+1;i++){
		sumA[i] = sumA[i-1] + A[i-1];
		if(sumA[i] > K)sumA[i] = K;
		else li = i;
	}
	long ans = li;
	long sumB = 0;
	for(long j=0;j<M;j++){
		sumB += B[j];
		if (sumB > K)break;
		while(sumB + sumA[li] > K && li > 0){
			li--;
		}
		// cout << j + li + 2 << ";" << j << ":" << li << endl;
		ans = max(ans, j + li + 1);
	}
	cout << ans << endl;
}
