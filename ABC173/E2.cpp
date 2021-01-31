#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000000 + 7;

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

int main(){
	int N, K;
	cin >> N >> K;
	vector<long long> A;
	int mis = 0;
	for(int i=0;i<N;i++){
		long long X;
		cin >> X;
		A.push_back(X);
		if(X < 0)mis++;
	}
	sort(A.begin(), A.end());
	// for(int i=0;i<N;i++){
	// 	cout << i << ":" << A[i] << endl;
	// }
	long long ans = 1;
	if(N == K){
		for(int i=0;i<N;i++){
			ans = modmul(ans, A[i]);
		}
	}
	else if(K % 2 == 1 && mis == N){
		for(int i=0;i<K;i++){
			ans = modmul(ans, A[N - i - 1]);
		}
	}
	else{
		int cnt = 0;
		vector<long long> M, P;
		for(int i=0;i<N;i++){
			if(A[i] < 0)M.push_back(A[i]);
			else P.push_back(A[i]);
		}
		reverse(P.begin(), P.end());
		int Mi = 0, Pi = 0;
		int MN = M.size(), PN = P.size();
		while(cnt < K){
			long long tmpP = -1, tmpM = -1;
			if(Pi + 1 < PN)tmpP = P[Pi] * P[Pi + 1];
			else if(Pi + 1 == PN)tmpP = P[Pi];
			if(Mi + 1 < MN)tmpM = M[Mi] * M[Mi + 1];
			if(tmpP > tmpM || cnt == K - 1){
				ans = modmul(ans, P[Pi]);
				Pi++;
				cnt++;
			}
			else{
				ans = modmul(ans , tmpM);
				Mi += 2;
				cnt += 2;
			}
			//cout << ans << endl;
		}
	}
	cout << ans << endl;
}
