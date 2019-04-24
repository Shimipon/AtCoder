#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
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
	long long ans = a * b;
	ans %= mod;
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
	long long N;
	cin >> N;
	vector<long long> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	
}