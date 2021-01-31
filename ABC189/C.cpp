#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int A[N];
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	int ans = 0;
	for(int i=0;i<N;i++){
		int now=0, nmax=0;
		for(int j=0;j<N;j++){
			if(A[j] >= A[i]){
				now++;
				nmax = max(nmax, A[i] * now);
			}
			else now = 0;
		}
		ans = max(nmax, ans);
	}
	cout << ans << endl;
}
