#include <bits/stdc++.h>
using namespace std;

int main(){
	long long N;
	cin >> N;
	long long A[N];
	long long SUM = 0;
	long long ans = 0;
	for(long long i=0;i<N;i++){
		cin >> A[i];
		SUM += A[i];
		ans += (N-1) * A[i] * A[i];
	}
	for(long long i=0;i<N;i++){
		SUM -= A[i];
		ans -= 2 * A[i] * SUM;
	}
	cout << ans << endl;
}
