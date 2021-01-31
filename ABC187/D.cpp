#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	long long A[N], B[N];
	long long Tk = 0, Ao = 0;
	for(int i=0;i<N;i++){
		cin >> A[i] >> B[i];
		Ao += A[i];
	}
	vector<pair<long long, int>> C;
	for(int i=0;i<N;i++){
		pair<long long, int> x;
		x.first = 2 * A[i] + B[i];
		x.second = i;
		C.push_back(x);
	}
	int ans = 0;
	sort(C.rbegin(),C.rend());
	while(Tk <= Ao){
		Tk += A[C[ans].second] + B[C[ans].second];
		Ao -= A[C[ans].second];
		ans++;
	}
	cout << ans << endl;
}
