#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	int a[N];
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	int ans = 0;
	for(int i=0;i<N;i++){
		if(i % 2 == 0 && a[i] % 2 == 1)ans++;
	}
	cout << ans << endl;
}
