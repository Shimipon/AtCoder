#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int D, G;
	cin >> D >> G;
	vector<int> p(D),c(D);
	for(int i=0;i<D;i++){
		cin >> p[i] >> c[i];
	}
	int ans = 10000000;
	for(int s = 0;s < (1 << D);s++){
		int SUM = 0, NUM = 0, rest_i = -1;
		for(int i=0;i<D;i++){
			if(s >> i & 1){
				SUM += p[i] * (i + 1) * 100 + c[i];
				NUM += p[i];
			}
			else{
				rest_i = i;
			}
		}
		if(SUM < G){
			int need = (G - SUM) / (100 * (rest_i + 1));
			if ((G - SUM) % (100 * (rest_i + 1)) > 0) need++;
			if(need < p[rest_i]) NUM += need;
			else NUM = 10000000;
		}
		ans = min(NUM,ans);
	}
	cout << ans << endl;
}