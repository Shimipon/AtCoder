#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int main(){
	string S;
	long int K;
	cin >> S >> K;
	long int length = (long int)S.size();
	char ans = '1';
	for(int i=0;i<min(length,K);i++){
		if(*(S.begin() + i) != '1'){
			ans = *(S.begin() + i);
			break;
		}
	}
	cout << ans << endl;
}