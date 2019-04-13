#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
using namespace std;

int main(){
	string S;
	cin >> S;
	int N = (int)S.size();
	int count1 = 0, count2 = 0;
	for(int i=0;i<N;i++){
		if(S[i] == '0' && i % 2)count1++;
		if(S[i] == '1' && !(i % 2))count1++;  
	}
	for(int i=0;i<N;i++){
		if(S[i] == '1' && i % 2)count2++;
		if(S[i] == '0' && !(i % 2))count2++;  
	}
	cout << min(count1, count2) << endl;
}