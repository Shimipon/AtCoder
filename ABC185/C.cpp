#include <bits/stdc++.h>
using namespace std;

int main(){
	long long L;
	cin >> L;
	long long ans = 1;
	for(int i=1;i<=11;i++){
		ans *= L - i;
		ans /= i;
	}
	cout << ans << endl;
}
