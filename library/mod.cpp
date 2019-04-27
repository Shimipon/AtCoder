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

vector<ll> FIB(10,0);
ll fib(ll n){
	if(FIB[n] != 0)return FIB[n];
	if(n == 0){
		FIB[n] = 1;
		return FIB[n];
	}
	if(n == 1){
		FIB[n] = 2;
		return FIB[n];
	}
	FIB[n] = modplus(fib(n-1), fib(n-2));
	return FIB[n];
}