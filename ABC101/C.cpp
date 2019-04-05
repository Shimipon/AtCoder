#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
using namespace std;

int main(){
	long long N, K;
	cin >> N >> K;
	vector<long long> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	long long ans = (N - 1) / (K - 1);
	if((N - 1) % (K - 1) > 0) ans++;
	cout << ans << endl;
}