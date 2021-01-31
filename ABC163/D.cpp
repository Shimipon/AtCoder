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

int main(){
	long long N, K;
	cin >> N >> K;
	long long ans = 0;
	for(long long i=K;i<=N+1;i++){
		long long l = i * (i - 1) / 2;
		long long r = i * (2 * N - i + 1) / 2;
		ans = modplus(ans, modminus(r + 1, l));
		// cout << ans << endl;
	}
	cout << ans << endl;
}