#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> node;

int MAX_N = 100000;
vector<node> unionfind(MAX_N);
vector<int> size(MAX_N);
void init(int N){
	for(int i=0;i<N;i++){
		unionfind[i].first = i;
		unionfind[i].second = 0;
		size[i] = 1;
	}
}

int find(int n){
	if(unionfind[n].first == n){
		return n;
	}
	else{
		unionfind[n].first = find(unionfind[n].first);
		return unionfind[n].first;
	}
}

void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(unionfind[x].second > unionfind[y].second){
		unionfind[x].first = y;
		size[y] += size[x];
		size[x] = 0;
	} 
	else{
		unionfind[y].first = x;
		size[x] += size[y];
		size[y] = 0;

	}
	if(unionfind[x].second == unionfind[y].second){
		unionfind[x].second++;
	}
}

bool same(int x, int y){
	return find(x) == find(y);
}

int main(){
	int N, M;
	cin >> N >> M;
	vector<int> A(M), B(M);
	for(int i=0;i<M;i++){
		cin >> A[i] >> B[i];
	}
	vector<ll> ans(M);
	init(N);
	ans[M-1] = (ll)N * (N-1) / 2;
	for(int i=M-2;i>=0;i--){
		if(same(A[i + 1]-1, B[i + 1]-1)) ans[i] = ans[i+1];
		else ans[i] = ans[i+1] - (ll)(size[find(A[i+1]-1)] * size[find(B[i+1]-1)]);
		//cout << "Ai:" << A[i+1]-1<< ":" <<size[find(A[i+1]-1)] 
		//	<< " Bi:" << B[i+1]-1<< ":" <<size[find(B[i+1]-1)] << endl;
		unite(A[i+1]-1,B[i+1]-1);
	}
	for(int i=0;i<M;i++){
		cout << ans[i] << endl;
	}
}