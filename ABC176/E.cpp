#include <bits/stdc++.h>
using namespace std;

int main(){
	int H, W, M;
	queue<int> q1;
	queue<int> q2;
	cin  >> H >> W >> M;
	int h[M], w[M];
	long long r1[H], r2[W];
	long long MR1 = 0, MR2 = 0;
	for(int i=0;i<H;i++){
		r1[i] = 0;
	}
	for(int i=0;i<W;i++){
		r2[i] = 0;
	}
	for(int i=0;i<M;i++){
		cin >> h[i] >> w[i];
		h[i]--;
		w[i]--;
		r1[h[i]]++;
		r2[w[i]]++;
		MR1 = max(MR1, r1[h[i]]);
		MR2 = max(MR2, r2[w[i]]);
	}
	vector<int> A, B;
	long long ans = MR1 + MR2 - 1;
	for(int i=0;i<H;i++){
		if(r1[i] == MR1) A.push_back(i);
	}
	for(int i=0;i<W;i++){
		if(r2[i] == MR2) B.push_back(i);
	}
	long long num = (long long)A.size() * (long long)B.size();
	long long cnt = 0;
	for(int i=0;i<M;i++){
		bool chk1 = binary_search(A.begin(), A.end(), h[i]);
		bool chk2 = binary_search(B.begin(), B.end(), w[i]);
		if(chk1 && chk2) cnt++;
	}
	if(cnt < num)ans++;
	cout << ans << endl;
}
