#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	bool check = false;
	check = (abs(a - c) <= d);
	check = check || (abs(a - b) <= d && abs(b - c) <= d);
	if(check)cout << "Yes" << endl;
	else cout << "No" << endl;
}