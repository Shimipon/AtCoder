#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int> A;
	for(int i=0;i<N;i++){
		int x;
		cin >> x;
		A.push_back(x);
	}
	sort(A.begin(), A.end());
	int Amax = A[N-1];
	int chk[Amax + 1];
	for(int i=0;i<=Amax;i++){
		chk[i] = 0;
	}
	for(int i = 0;i<N;i++){
		if(chk[A[i]] == 0){
			for(int j=2;j * A[i]<=Amax;j++){
				chk[j * A[i]]++;
			}
		}
		if(i > 0 && A[i] == A[i - 1])chk[A[i]]++;
	}
	// for(int i=0;i<=Amax;i++){
	// 	cout << i << ":" << chk[i] << endl;
	// }
	int ans = 0;
	for(int i=0;i<N;i++){
		if(chk[A[i]] == 0)ans++;
	}
	cout << ans << endl;
}
