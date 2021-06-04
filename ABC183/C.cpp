#include <bits/stdc++.h>
using namespace std;

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

int main(){
	int N, K;
	cin >> N >> K;
	int T[N][N];
	for(int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			cin >> T[i][j];
		}
	}
	vector<int> A(N-1);
	iota(A.begin(), A.end(), 1);
	int ans = 0;
	do {
		int Sum = 0;
		Sum += T[0][A[0]];
        for(int i=0;i<N-2;i++){
        	Sum += T[A[i]][A[i+1]];
        }
        Sum += T[A[N-2]][0];
        if(Sum == K)ans++;
        // printVector(A);
    } while (next_permutation(A.begin(), A.end()));
    cout << ans << endl;
}


AssertionError: 答えが誤っています。

  答えは-1ですが、あなたのコードは他のものを出力しています。

  #### 入力:

  12 16

  5 5 9 5 4 9 4 10 9 10 3 6 11 2 7 9

  1 4 2 3 12 7 8 5 10 11 6 9
  1 4 2 3 6 7 8 5 10 11 12 9
  #### あなたの答え:

2 1 5 3 4 7 9 8 6
2 1 5 3 4 7 6 8 9