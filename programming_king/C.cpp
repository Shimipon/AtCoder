#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, int> p;
int main(){
	int N;
	cin >> N;
	vector<ll> A(N);
	vector<ll> B(N);
	for(int i=0;i<N;i++){
		cin >> A[i] >> B[i];
	}
	vector<p> point(N);
	for(int i=0;i<N;i++){
		point[i].first = A[i] + B[i];
		point[i].second = i;
	}
	sort(point.rbegin(),point.rend());
	ll sumA=0, sumB=0;
	for(int i=0;i<N;i++){
		if(i % 2) sumB += B[point[i].second];
		else sumA += A[point[i].second];
	}
	cout << sumA - sumB << endl;
}