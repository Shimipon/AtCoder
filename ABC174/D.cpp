#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	char c[N];
	int wi = N, ri = -1;
	for(int i=0;i<N;i++){
		cin >> c[i];
		if(c[i] == 'R') ri = i;
		if(c[i] == 'W' && wi == N) wi = i;
	}
	int ans = 0;
	while(wi < ri){
		c[wi] = 'R';
		c[ri] = 'W';
		ans++;
		while(c[wi] == 'R' && wi < N){
			wi++;
		}
		while(c[ri] == 'W' && ri > -1){
			ri--;
		}
	}
	cout << ans <<
}
