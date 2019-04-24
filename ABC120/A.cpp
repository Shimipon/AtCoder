#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <vector>
using namespace std;
int main(){
	int A, B, C;
	cin >> A >> B >> C;
	int kai = B / A;
	if(kai > C){
		cout << C << endl;
	}	
	else{
		cout << kai << endl;
	}
}