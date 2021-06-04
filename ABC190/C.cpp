#include <bits/stdc++.h>
using namespace std;

int POW(int A, int P){
	int a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	int adash = a * a;
	if(p % 2) return POW(adash, p / 2) * a;
	else return POW(adash, p / 2);
}


int main(){
	int N, M;
	cin >> N >> M;
	int A[M], B[M];
	for(int i=0;i<M;i++){
		cin >> A[i] >> B[i];
		A[i]--;
		B[i]--;
	}
	int K;
	cin >> K;
	int C[K], D[K];
	for(int i=0;i<K;i++){
		cin >> C[i] >> D[i];
		C[i]--;
		D[i]--;
	}
	int L = POW(2, K), ans = 0;
	int E[N];
	for(int i=0;i<N;i++){
		E[i] = 0;
	}
	for(int j=0;j<L;j++){
		int tmp = j,cnt = 0;
		for(int k=0;k<K;k++){
			if(tmp % 2)E[C[k]]++;
			else E[D[k]]++;
			tmp /= 2;
		}
		// for(int i=0;i<N;i++){
		// 	cout << i << ":" << E[i] << endl;
		// }
		for(int m=0;m<M;m++){
			if(E[A[m]] > 0 && E[B[m]] > 0)cnt++;
		}
		ans = max(ans, cnt);
		for(int i=0;i<N;i++){
			E[i] = 0;
		}
		// cout << j << "j" << cnt << endl;
	}
	cout << ans << endl;
}
