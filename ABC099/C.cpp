#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int pow(int A, int P){
	int a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	int adash = a * a;
	if(p % 2) return pow(adash, p / 2) * a;
	else return pow(adash, p / 2);
}

int main(){
	int N;
	cin >> N;
	int count = 1000000;
	for(int i=0;i<=N;i++){
		int count1 = 0;
		int t = i;
		while(t>0){
			count1 += t % 6;
			t /= 6;
		}
		t = N - i;
		while(t>0){
			count1 += t % 9;
			t /= 9;
		}
		count = min(count, count1);
	}
	cout << count << endl;
}