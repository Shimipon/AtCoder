#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	int A[N];
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	int C[N];
	for(int i=0;i<N;i++){
		C[i] = 0;
	}
	int st = 0;
	int ans = N;
	int mex = 0, premex = -1;
	for(int i=0;i<N;i++){
		C[A[i]]++;
		if(mex == A[i] && premex >= 0) mex = premex;
		while(C[mex] > 0){
			mex++;
		}
		if(i-st+1 > M){
			C[A[st]]--;
			if(C[A[st]] <= 0){
				premex = mex;
				mex = A[st];
			}
			st++;
		}
		if(i-st+1== M){
			ans = min(ans, mex);
		}
	}
	cout << ans << endl;
}
