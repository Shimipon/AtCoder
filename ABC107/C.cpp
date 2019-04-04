#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int main(){
	int N, K;
	cin >> N >> K;
	vector<long int> x(N);
	for(int i=0;i<N;i++){
		cin >> x[i];
	}
	long int ans = 1000000000;
	for(int i=0;i+K-1<N;i++){
		long int left = x[i];
		long int right = x[i+K-1];
		if(left < 0 && right < 0) ans = min(0 - left, ans);
		else if(left < 0 && right > 0) ans = min(right - left + min(right, -1 * left), ans);
		else ans = min(right, ans);
	}
	cout << ans << endl;
}