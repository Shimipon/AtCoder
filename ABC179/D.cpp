#include <bits/stdc++.h>
using namespace std;

long long mod = 998244353;

long long modplus(long long a, long long b){
	long long ans = a + b;
	ans %= mod;
	return ans;
}

long long modminus(long long a, long long b){
	long long ans = a - b;
	ans %= mod;
	if(ans < 0) ans += mod;
	return ans;
}

long long modmul(long long a, long long b){
	long long ans = (a % mod) * (b % mod);
	ans = ((ans % mod) + mod) % mod;
	return ans;
}

long long modpow(long long A, long long P){
	long long a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	long long adash = modmul(a,a);
	if(p % 2) return modmul(modpow(adash, p / 2), a);
	else return modpow(adash, p / 2);
}

long long moddiv(long long a, long long b){
	long long divisor = modpow(b, mod - 2);
	return modmul(a,divisor);
}

int main(){
	int N, K;
	cin >> N >> K;
	int L[K], R[K];
	for(int i=0;i<K;i++){
		cin >> L[i] >> R[i];
		L[i];
		R[i];
	}
	long long dp[N];
	long long dpsum[N+1];
	dp[N-1] = 1;
	dpsum[N] = 0;
	dpsum[N-1] = 1;
	for(int i=0;i<N-1;i++){
		dp[i] = 0;
		dpsum[i] = 0;
	}
	for(int i=N-2;i>=0;i--){
		for(int j=0;j<K;j++){
			int l = L[j] + i;
			int r = R[j] + i + 1;
			if(l > N-1) continue;
			if(r > N) r = N;
			dp[i] = modplus(dp[i], 
				modminus(dpsum[l], dpsum[r]));
		}
		dpsum[i] = modplus(dp[i],dpsum[i+1]);
	}
	// for(int i=0;i<N;i++){
	// 	cout << i << ":" << dp[i] << endl;
	// }
	cout << dp[0] << endl;
}
