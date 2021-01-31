#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	long long X[N], Y[N];
	for(int i=0;i<N;i++){
		cin >> X[i] >> Y[i];
	}
	int M;
	cin >> M;
	int op[M][2];
	for(int i=0;i<M;i++){
		cin >> op[i][0];
		if(op[i][0] >= 3)cin >> op[i][1];
	}
	int Q;
	cin >> Q;
	int A[Q], B[Q];
	vector<pair<pair<int, int>, int>> V;
	for(int i=0;i<Q;i++){
		cin >> A[i] >> B[i];
		B[i]--;
		pair<int, int> x;
		x.first = A[i];
		x.second = B[i];
		pair<pair<int, int>, int> y;
		y.first = x;
		y.second = i;
		V.push_back(y);
	}
	long long ans[Q][2];
	int xory = 0;
	long long xa = 1, ya = 1;
	long long xp = 0, yp = 0;
	sort(V.begin(),V.end());
	int nowq = 0;
	for(int i=0;i<M;i++){
		// cout << i << endl;
		while(V[nowq].first.first == i){
			if(xory == 0){
				ans[V[nowq].second][0] = xa * X[V[nowq].first.second] + xp;
				ans[V[nowq].second][1] = ya * Y[V[nowq].first.second] + yp;
			}
			else{
				ans[V[nowq].second][0] = xa * Y[V[nowq].first.second] + xp;
				ans[V[nowq].second][1] = ya * X[V[nowq].first.second] + yp;
			}
			// cout << nowq << ":" << V[nowq].second << endl;
			nowq++;
		}
		if(op[i][0] == 1){
			xory = (xory + 1) % 2;
			long long tmp = xp;
			xp = yp;
			yp = -1 * tmp;
			tmp = xa;
			xa = ya;
			ya = -1 * tmp;
		}
		else if(op[i][0] == 2){
			xory = (xory + 1) % 2;
			long long tmp = xp;
			xp = -1 * yp;
			yp = tmp;
			tmp = xa;
			xa = -1 * ya;
			ya = tmp;
		}
		else if(op[i][0] == 3){
			xa *= -1;
			xp *= -1;
			xp += 2 * op[i][1];
		}
		else if(op[i][0] == 4){
			ya *= -1;
			yp *= -1;
			yp += 2 * op[i][1];
		}
	}
	while(V[nowq].first.first == M){
		if(xory == 0){
			ans[V[nowq].second][0] = xa * X[V[nowq].first.second] + xp;
			ans[V[nowq].second][1] = ya * Y[V[nowq].first.second] + yp;
		}
		else{
			ans[V[nowq].second][0] = xa * Y[V[nowq].first.second] + xp;
			ans[V[nowq].second][1] = ya * X[V[nowq].first.second] + yp;
		}
		nowq++;
	}
	for(int i=0;i<Q;i++){
		cout << ans[i][0] << " " << ans[i][1] << endl;
	}
}
