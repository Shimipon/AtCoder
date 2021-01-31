#include <bits/stdc++.h>
using namespace std;

long long Euclidean(long long a, long long b) {
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= (a/b) * x;
    return d;
}

int main(){
	int T;
	cin >> T;
	for(int t = 0;t<T;t++){
		long long N, S, K;
		cin >> N >> S >> K;
		long long Mcd = Euclidean(N, K);
		if(S % Mcd > 0){
			cout << -1 << endl;
		}
		else{
			long long x,y;
			extGCD(N, K,x,y);
			// cout << y << endl;
			y *= -1;
			y *= (S / Mcd);
			long long tmpN = N / Euclidean(N, K);
			y %= tmpN;
			if(y < 0)y+= tmpN;
			cout << y << endl;
		}
	}
}
