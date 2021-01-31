#include <bits/stdc++.h>
using namespace std;

int Euclidean(int A, int B){
	int temp;
	int ma = max(A, B), mb = min(A, B);
	while(mb != 0){
		temp = mb;
		mb = ma % mb;
		ma = temp;
	}
	return ma;
}

int main(){
	int N;
	cin >> N;
	int A[N];
	int D[1000001];
	int IN[1000001];
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	for(int i=0;i<1000001;i++){
		IN[i] = 0;
		D[i] = i;
	}
	for(int i=2;i*i<=1000000;i++){
		for(int j=1;j*i<=1000000;j++){
			D[j*i] = min(D[j*i], i);
		}
	}
	int gcd = A[0];
	for(int i=1;i<N;i++){
		gcd = Euclidean(gcd, A[i]);
	}
	bool pc = true;
	for(int i=0;i<N;i++){
		int tmp = A[i];
		while(tmp > 1){
			if(IN[D[tmp]] > 0){
				pc = false;
				break;
			}
			else{
				IN[D[tmp]]++;
				int div = D[tmp];
				while(tmp % div == 0)tmp /= div;
			}
		}
	}
	// for(int i=0;i<6;i++){
	// 	cout << IN[i] << endl;
	// }
	if(pc) cout << "pairwise coprime" << endl;
	else if(gcd == 1) cout << "setwise coprime" << endl;
	else cout << "not coprime" << endl;
}