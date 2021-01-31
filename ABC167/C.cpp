#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, M, X;
	cin >> N >> M >> X;
	int C[N], A[N][M];
	for(int i=0;i<N;i++){
		cin >> C[i];
		for(int j=0;j<M;j++){
			cin >> A[i][j];
		}
	}
	int ans = 100000000;
	for(int l = 0;l<(1 << N);l++){
		int lc = l;
		int B[M];
		for(int i=0;i<M;i++){
			B[i] = 0;
		}
		int V = 0;
		for(int i=0;i<N;i++){
			if (lc % 2){
				V += C[i];
				for(int j=0;j<M;j++){
					B[j] += A[i][j];
				}
			}
			lc /= 2;
		}
		bool chk = true;
		for(int j = 0;j<M;j++){
			if(B[j] < X){
				chk = false;
				break;
			}
		}
		if(chk){
			ans = min(ans, V);
			//cout << l << ":" <<  V << endl;
		}
	}
	if(ans == 100000000) ans = -1;
	cout << ans << endl;
}