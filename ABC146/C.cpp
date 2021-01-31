#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
int main(){
	long long A, B, X;
	cin >> A >> B >> X;
	long long mid = (INF + 1) / 2;
	long long r = INF, l = 0;
	while(r != l){
		long long K = A * mid;
		long long cnt = 0, tmp = mid;
		while(tmp > 0){
			tmp /= 10;
			cnt++;
		}
		K += cnt * B;
		if(K <= X)l = mid;
		else r = mid - 1;
		mid = (r + l + 1) / 2;
	}
	cout << r << endl;
}