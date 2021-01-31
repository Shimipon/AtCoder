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

long long moddiv(long long a, long long b){
	long long divisor = modpow(b, mod - 2);
	return modmul(a,divisor);
}

long long comb(long long n, long long m){
	if(n == 0)return 1;
	if(m == 0)return 1;
	if(n < m) return 0;
	long long ans = 1;
	for(long long i=0;i<m;i++){
		ans = modmul(ans, n-i);
	}
	for(long long i=0;i<m;i++){
		ans = moddiv(ans, i+1);
	}
	return ans;
}

int main(){
	long long S;
	cin >> S;
	long long A[S+1];
	A[0] = 1;
	for(int i=1;i<min((long long)3,S + 1);i++){
		A[i] = 0;
		// cout << A[i] << endl;
	}
	// cout << A[3] << endl;
	for(int i = 3;i<=S;i++){
		long long tmp = 0;
		for(int j=0;j<=i-3;j++){
			tmp = modplus(tmp, A[j]);
		}
		A[i] = tmp;
	}
	// for(int i=0;i<=S;i++){
	// 	cout << A[i] << endl;
	// }
	cout << A[S] << endl;
}