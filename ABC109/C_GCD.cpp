#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GCD(int x, int y){
	if(y == 0) return x;
	return GCD(y, x % y);
}

int main(){
	int N, X;
	cin >> N >> X;
	vector<long int> x(N);
	for(int i=0;i<N;i++){
		cin >> x[i];
	}
	vector<long int> zahyo;
	zahyo.push_back(X);
	for(int i=0;i<N;i++){
		zahyo.push_back(x[i]);
	}
	sort(zahyo.begin(), zahyo.end());
	vector<long int> v;
	for(int i=0;i<N;i++){
		v.push_back(zahyo[i+1] - zahyo[i]);
	}
	int ans =  GCD(v[0], v[1]);
	for(int i=2;i<N;i++){
		ans = GCD(ans, v[i]);
	}
	cout << ans << endl;
}