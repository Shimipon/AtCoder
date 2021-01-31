#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, K;
	cin >> N >> K;
	int a[N];
	int c[N];
	for(int i=0;i<N;i++){
		c[i] = 0;
	}
	for(int i=0;i<N;i++){
		cin >> a[i];
		c[a[i]]++;
	}
	int ans = 0;
	for(int i=0;i<K;i++){
		int j = 0;
		while(c[j] > 0){
			c[j]--;
			j++;
		}
		ans += j;
	}
	cout << ans << endl;
}
