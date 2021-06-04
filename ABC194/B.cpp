#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int A[N], B[N];
	int ma = 100000, mb = 100000;
	int mai = -1,mbi = -1;
	int ma2 = 100000, mb2 = 100000;
	for(int i=0;i<N;i++){
		cin >> A[i] >> B[i];
		if(ma >= A[i]){
			mai = i;
			ma2 = ma;
			ma = A[i]; 
		}
		if(mb >= B[i]){
			mbi = i;
			mb2 = mb;
			mb = B[i];
		}
	}
	int ans = 2000000;
	if(mai != mbi) ans = max(ma,mb);
	else{
		ans = min(max(ma,mb2),max(mb,ma2));
		ans = min(ans, ma + mb);
	}
	cout << ans << endl;
}
