#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

ll mod = 1000000000 + 7;

ll modplus(ll a, ll b){
	ll ans = a + b;
	ans %= mod;
	return ans;
}
ll modminus(ll a, ll b){
	ll ans = a - b;
	ans %= mod;
	if(ans < 0) ans += mod;
	return ans;
}
ll modmul(ll a, ll b){
	ll ans = a * b;
	ans %= mod;
	return ans;
}

ll modpow(ll A, ll P){
	ll a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	ll adash = modmul(a,a);
	if(p % 2) return modmul(modpow(adash, p / 2), a);
	else return modpow(adash, p / 2);
}
ll moddiv(ll a, ll b){
	ll divisor = modpow(b, mod - 2);
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

ll countLeft(ll n, ll W){
	ll left = n - 2;
	ll right = n + 1;
	ll ans = 1;
	if(left >= 0) ans = fib(left);
	if(right <= W-1) ans = modmul(fib(W - right - 1),ans);
	return ans;
}

ll countCenter(ll n, ll W){
	ll left = n - 1;
	ll right = n + 1;
	ll ans = 1;
	if(left >= 0) ans = fib(left);
	if(right <= W-1) ans = modmul(fib(W - right - 1),ans);
	return ans;
}
ll countRight(ll n, ll W){
	ll left = n - 1;
	ll right = n + 2;
	ll ans = 1;
	if(left >= 0) ans = fib(left);
	if(right <= W-1) ans = modmul(fib(W - right - 1),ans);
	return ans;
}
int main(){
	ll H, W, K;
	cin >> H >> W >> K;
	ll count[H+1][W];
	for(ll i=0;i<H+1;i++){
		for(ll j=0;j<W;j++){
			count[i][j] = 0;
		}
	}
	count[0][0] = 1;
	for(ll i=0;i<H;i++){
		for(ll j=0;j<W;j++){
			if(j-1 >= 0) count[i+1][j-1] = modplus(modmul(count[i][j],countLeft(j,W)),count[i+1][j-1]);
			count[i+1][j] = modplus(modmul(count[i][j],countCenter(j,W)),count[i+1][j]);
			if(j+1 < W) count[i+1][j+1] = modplus(modmul(count[i][j],countRight(j,W)),count[i+1][j+1]);
		}
	}
	cout << count[H][K-1] << endl;
}