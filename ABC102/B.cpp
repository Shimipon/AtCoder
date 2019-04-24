#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<long long> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	long long ans = 0;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			ans = max(abs(A[i] - A[j]),ans);
		}
	}
	cout << ans << endl;
}