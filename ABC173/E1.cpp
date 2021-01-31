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
	long long ans = a * b;
	ans = (ans + mod) % mod;
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
		int tmpK = K;
		vector<long long> M, P;
		for(int i=0;i<N;i++){
			if(A[i] < 0)M.push_back(A[i]);
			else P.push_back(A[i]);
		}
		int MN = M.size(), PN = P.size();
		int Mi = 0, Pi = PN - 1;
		while(tmpK > 0){
			long long mul;
			if(Pi >= 0){
				if(Mi < MN - 1){
					long long tmpM = M[Mi] * M[Mi + 1];
					long long tmpP = P[Pi] * P[Pi - 1];
					if(tmpP < tmpM && tmpK > 1){
						mul = tmpM;
						tmpK -= 2;
						Mi += 2;
					}
					else{
						mul = P[Pi];
						tmpK--;
						Pi--;
					}
				}
				else{
					mul = P[Pi];
					tmpK--;
					Pi--; 
				}
			}
			else{
				mul = M[Mi] * M[Mi + 1];
				tmpK -= 2;
				Mi += 2;
			}
			ans = modmul(ans, mul);
		}
	}
	cout << ans << endl;
	// cout << ans - mod << endl;
	// long long l = 1;
	// for(int i=0;i<50;i++){
	// 	l = modmul(l , 10);
	// }
	// cout << l << endl;
}
