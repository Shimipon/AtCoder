#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	long long A[N];
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	vector<pair<int, int>> V;
	for(int i=0;i<M;i++){
		int x,y;
		cin >> x >> y;
		pair<int, int> a;
		a.first = x - 1;
		a.second = y - 1;
		V.push_back(a);
	}
	sort(V.begin(), V.end());
	// for(int i=0;i<M;i++){
	// 	cout << V[i].first << ":" << V[i].second << endl;
	// }
	long long Min[N], Max[N];
	for(int i=0;i<N;i++){
		Min[i] = A[i];
		Max[i] = -10000000000;
	}
	for(int i=0;i<M;i++){
		Max[V[i].second] = 
			max(max(Max[V[i].first], A[V[i].second] - Min[V[i].first])
				, Max[V[i].second]);
		Min[V[i].second] = 
			min(Min[V[i].second], min(Min[V[i].first], A[V[i].second]));
		// cout << Max[V[i].second] << endl;
	}
	long long ans = -10000000000;
	for(int i=0;i<N;i++){
		ans = max(ans, Max[i]);
	}
	cout << ans << endl;
}

