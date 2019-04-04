#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	long long N;
	cin >> N;
	vector<long long> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	vector<long long> B(N);
	for(int i=0;i<N;i++){
		B[i] = A[i] - i;
	}
	sort(B.begin(), B.end());
	long long center1, center2;
	if(N % 2) {
		center1 = B[N / 2];
		center2 = B[N / 2];
	}
	else{
		center1 = B[N / 2];
		center2 = B[N / 2 - 1];
	}
	long long ans1, ans2;
	for(int i=0;i<N;i++){
		ans1 += abs(B[i] - center1);
		ans2 += abs(B[i] - center2);
	}
	cout << min(ans1, ans2) << endl;
}