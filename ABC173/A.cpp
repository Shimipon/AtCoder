#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	N %= 1000;
	if(N == 0){
		cout << 0 << endl;
	}
	else cout << 1000 - N << endl;
}
