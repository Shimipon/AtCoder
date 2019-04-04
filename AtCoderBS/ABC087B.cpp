#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	long long A, B, C, X;
	cin >> A >> B >> C >> X;
	long long count = 0;
	for(int i=0;i * 500 <= X && i <= A;i++){
		for(int j=0;j * 100 + i * 500<=X && j <= B;j++){
			if((X - (j * 100 + i * 500)) / 50 <= C) count++;
		}
	}
	cout << count << endl;
}