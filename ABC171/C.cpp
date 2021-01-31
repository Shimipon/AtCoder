#include <bits/stdc++.h>
using namespace std;


long pow(long A, long P){
	long a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	long adash = a * a;
	if(p % 2) return pow(adash, p / 2) * a;
	else return pow(adash, p / 2);
}

int main(){
	long N;
	cin >> N;
	long tmpN = N;
	long i = 1;
	tmpN--;
	while(tmpN - pow(26, i) >= 0){
		tmpN -= pow(26, i);
		i++;
	}
	string ans = "";
	for(long j = 0;j<i;j++){
		long keta = pow(26, i - j - 1);
		long num = tmpN / keta;
		char pls = 'a' + num;  
		ans = ans + pls;
		tmpN = tmpN % keta;
	}
	cout << ans << endl;
}
