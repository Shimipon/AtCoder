#include <bits/stdc++.h>
using namespace std;
int main(){
	long N;
	cin >> N;
	int A[1000001];
	for(int i=0;i<=1000000;i++){
		A[i] = 0;
	}
	long NC = N;
	for(int i = 2;i<=1000000;i++){
		while(NC % i == 0){
			NC /= i;
			A[i]++;
		}
		if(NC == 1) break;
	}
	int ans = 0;
	for(int i = 2;i<=1000000;i++){
		int j=1;
		while(A[i] >= j){
			A[i] -= j;
			ans++;
			j++;
		}
	}
	if(NC != 1)ans++;
	cout << ans << endl;
}
