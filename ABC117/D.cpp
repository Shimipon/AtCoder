#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

long long pow(long long A, long long P){
	long long a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	long long adash = a * a;
	if(p % 2) return pow(adash, p / 2) * a;
	else return pow(adash, p / 2);
}
int main(){
	long long N, K;
	cin >> N >> K;
	vector<long long> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	vector<long long> on(41,0);
	for(int i=0;i<N;i++){
		long long j=0;
		long long Adash = A[i];
		while(Adash > 0){
			if(Adash % 2) on[j]++;
			j++;
			Adash /= 2;
		}
	}
	long long ans = 0;
	for(long long i=0;i<=40;i++){
		if(((K + 1) >> i) % 2 == 0)continue;
		long long ansdash = 0;
		long long Kdash = 0;
		for(int j=0;j<i;j++){
			if(on[j] <= N - on[j]) Kdash += pow(2,j);
		}
		for(int j=i+1;j<=40;j++){
			if(((K + 1) >> j) % 2) Kdash += pow(2,j);
		}
		for(int i=0;i<N;i++){
			ansdash += Kdash ^ A[i];
		}
		ans = max(ansdash,ans);
	}
	cout << ans << endl;
}