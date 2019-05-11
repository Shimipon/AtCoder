#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int N;
	cin >> N;
	if(N <= 999) printf("ABC\n", N);
	else printf("ABD\n", N - 999);
}