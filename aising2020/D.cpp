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

long long popcount(long long x){
	long long popc = 0;
	while(x > 0){
		if(x % 2 == 1) popc++;
		x /= 2;
	}
	return popc;
}

int func(char a, long long i, long long N, long long Xpp, long long Xpm, long long popc){
	int ans = 0;
	long long tmp = 0;
	if(a == '0'){
		mod = popc + 1;
		tmp = modplus(Xpp, modpow(2, N - i - 1));
		ans++;
	}
	else{
		if(popc == 1) return ans;
		mod = popc - 1;
		tmp = modminus(Xpm, modpow(2, N - i - 1));
		ans++;
	}
	while(tmp > 0){
		tmp %= popcount(tmp);
		ans++;
	}
	return ans;
}

int main(){
	long long N;
	string X;
	cin >> N >> X;
	long long popc = 0;
	for(long long i=0;i<N;i++){
		if(X[i] == '1')popc++;
	}
	long long Xpp = 0;
	mod = popc + 1;
	for(long long i=0;i<N;i++){
		if(X[i] == '1'){
			Xpp = modplus(Xpp, modpow(2, N - i - 1));
		}
	}
	long long Xpm = 0;
	mod = popc - 1;
	if(mod > 0){
		for(long long i=0;i<N;i++){
			if(X[i] == '1'){	
				Xpm = modplus(Xpm, modpow(2, N - i - 1));
			}
		}
	}
	for(long long i=0;i<N;i++){
		cout << func(X[i], i, N, Xpp, Xpm, popc) << endl;
	}
}
