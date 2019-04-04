#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main(){
	long int N, K;
  	cin >> N >> K;
  	long int count1 = 0;
  	long int count2 = 0;
	if(K % 2 == 1) count1 = N / K;
	else { 
		count1 = N / K;
		count2 = N / (K / 2) - count1;
	}
	cout << count1 * count1 * count1 + count2 * count2 * count2 << endl;
}