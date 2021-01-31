#include <bits/stdc++.h>
using namespace std;

int G[17][131072];
int C[17][17];
int sales(int N, int set, int MN){
	if (G[N][set] >= 0){
		// cout << N << ":" << set << ":" << G[N][set] << endl;
		return G[N][set];
	}
	int ans = 1000000000;
	for(int i=0;i < MN;i++){
		if(((1 << i) & set) == 1 << i){
			ans = min(ans, sales(i + 1, (set - (1 << i)), MN) + C[N][i+1]);
			// cout << sales(i + 1, (set - (1 << i)), MN) + C[N][i+1] << endl;
		}
	}
	G[N][set] = ans;
	// cout << N << ":" << set << ":" << ans << endl;
	return ans;
}

int main(){
	int N;
	cin >> N;
	int X[N], Y[N], Z[N];
	for(int i=0;i<N;i++){
		cin >> X[i] >> Y[i] >> Z[i];
		X[i]--;
		Y[i]--;
		Z[i]--;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			C[i][j] = abs(X[i] - X[j]) + abs(Y[i] - Y[j])
				+ max(0, Z[j] - Z[i]);
		}
	}
	for(int i=0;i<N;i++){
		G[i][0] = C[i][0];
		for(int j=1;j<(1 << (N - 1));j++){
			G[i][j] = -1;
		}
	}
	cout << sales(0,  (1 << (N - 1)) - 1, N) << endl;
}

