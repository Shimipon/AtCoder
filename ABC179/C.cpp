#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int ans = 0;
	for(int i=1;i<N;i++){
		ans += N / i;
		if(N % i == 0)ans--;
	}
	cout << ans << endl;
}
