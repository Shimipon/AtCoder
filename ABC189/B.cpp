#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	int X;
	cin >> N >> X;
	int V[N]; 
	int P[N];
	X *= 100;
	for(int i=0;i<N;i++){
		cin >> V[i] >> P[i];
	}
	int now = 0;
	int ans = -1;
	for(int i=0;i<N;i++){
		now += V[i] * P[i];
		if(now > X){
			ans = i + 1;
			break;
		}
	}
	cout << ans << endl;
}
