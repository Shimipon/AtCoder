#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, K;
	cin >> N >> K;
	int b[N];
	for(int i=0;i<K;i++){
		int d;
		cin >> d;
		for(int j=0;j<d;j++){
			int A;
			cin >> A;
			b[A - 1]++;
		}
	}
	int ans = 0;
	for(int i=0;i<K;i++){
		if(b[i] > 0) ans++;
	}
	cout << ans << endl;
}
