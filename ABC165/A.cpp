#include <bits/stdc++.h>
using namespace std;

int main(){
	int K, A, B;
	cin >> K >> A >> B;
	string ans = "NG";
	for(int i=A;i<=B;i++){
		if(i % K == 0) ans = "OK";
	}
	cout << ans << endl;
}
