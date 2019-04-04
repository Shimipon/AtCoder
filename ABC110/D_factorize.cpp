#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

vector<long long> item;
map<long long, long long> factor;
long long MOD = 1000000007;

long long modpow(long long a, long long p){
	if(p == 1) return a;
	long long adash = a * a % MOD;
	if(p % 2) return modpow(adash, p / 2) * a % MOD;
	return modpow(adash, p / 2);
}

void factorize(long long M){
	long long m = M;
	for(long long i=2;i*i<=M;i++){
		int check = 0;
		while(m % i == 0){
			factor[i]++;
			m /= i;
			check = 1;
		}
		if(check) item.push_back(i);
	}
	if(m != 1){
		factor[m] = 1;
		item.push_back(m);
	}
}

long long combination(long long N, long long K){
	if(K == 0) return 1;
	if(N == K) return 1;
	if(K > N - K) return combination(N, N - K);
	long long ans = 1;
	long long div = 1;
	for(long long i=1;i<=K;i++){
		ans *= N - i + 1;
		ans %= MOD;
		div *= i;
		div %= MOD;
	}
	return ans * modpow(div, MOD - 2) % MOD;
}
int main(){
	long long N, M;
	cin >> N >> M;
	factorize(M);
	long long ans = 1;
	for(int i = 0;i<(int)item.size();i++){
		ans *= combination(N - 1 +  factor[item[i]], factor[item[i]]);
		ans %= MOD;
	}
	cout << ans << endl;
}

