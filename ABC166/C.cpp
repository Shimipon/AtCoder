#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, M;
	cin >> N >> M;
	int H[N], A[M], B[M];
	for(int i=0;i<N;i++){
		cin >> H[i];
	}
	int R[N], G[N];
	for(int i=0;i<N;i++){
		R[i] = 0;
		G[i] = 0;
	}
	for(int j=0;j<M;j++){
		cin >> A[j] >> B[j];
		R[A[j] - 1]++;
		R[B[j] - 1]++;
		if (H[A[j] - 1] > H[B[j] - 1]) G[A[j] - 1]++;
		if (H[B[j] - 1] > H[A[j] - 1]) G[B[j] - 1]++;
	}
	int ans = 0;
	for(int i=0;i<N;i++){
		if(R[i] == G[i])ans++;
	}
	cout << ans << endl;
}
