#include <bits/stdc++.h>
using namespace std;

// C[]にnCmを入れて処理を行うを繰り返す

string S;
int N, l;
long long ans = 0;
int C[4];
// sにはN-1の値を、restにはMの値を引数として渡せばおけ
void recursive_comb(int s, int rest) {
	if (rest == 0) {
		if(C[0] == 0){
			long long t = 1;
			for(int i=1;i<N;i++){
				bool chk = false;
				for(int j=C[i-1] + 1;j<C[i];j++){
					if(S[C[j]] - '0' > 0){
						chk = true;
						break;
					}
				}
				if(chk) t*=9;
				else t *= S[C[i]] - '0';
			}
			ans += t;
			long long k = S[C[0]] - '0';
			k--;
			for(int i=0;i<N-1;i++){
				k *= 9;
			}
			ans += k;
			// cout << "t" << t << "k" << k << endl;
			// for(int i=0;i<N;i++){
			// 	cout <<  S[C[i]] - '0' << endl;
			// }
		}
		else{
			long long t = 9;
			for(int i=0;i<N-1;i++){
				t *= 9;
			}
			ans += t;
		}
		for(int i=0;i<N;i++){
			cout << C[i] << ":";
		}
		cout << ans << endl;
	}
	else {
		if (s < 0) return;
		recursive_comb(s - 1, rest);
		C[rest - 1] = s;
		recursive_comb(s - 1, rest - 1);
	}
}


int main(){
	cin >> S >> N;
	l = (int)S.length();
	recursive_comb(l - 1, N);
	cout << ans << endl;
}
