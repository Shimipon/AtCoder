#include <bits/stdc++.h>
using namespace std;
int main(){
	int A, B, C;
	int K;
	cin >> A >> B >> C >> K;
	int ans = 0;
	while(A >= B){
		B *= 2;
		ans++;
	}
	while(B >= C){
		C *= 2;
		ans++;
	}
	if(ans <= K) cout << "Yes" << endl;
	else cout << "No" << endl;
}
