#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
	int X, Y, Z, K;
	cin >> X >> Y >> Z >> K;
	vector<ll> A(X), B(Y), C(Z);
	for(int i=0;i<X;i++){
		cin >> A[i];
	}
	for(int i=0;i<Y;i++){
		cin >> B[i];
	}
	for(int i=0;i<Z;i++){
		cin >> C[i];
	}
	vector<ll> AB;
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++){
			AB.push_back(A[i] + B[j]);
		}
	}
	sort(AB.rbegin(),AB.rend());
	sort(C.rbegin(),C.rend());
	vector<ll> ans;
	for(int i=0;i<K;i++){
		for(int j=0;j<K;j++){
			if(j >= Z || i >= X * Y) continue;
			ans.push_back(AB[i] + C[j]);
		}
	}
	sort(ans.rbegin(),ans.rend());
	for(int i=0;i<K;i++){
		cout << ans[i] << endl;
	}
}