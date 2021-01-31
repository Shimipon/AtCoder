#include <bits/stdc++.h>
using namespace std;

int main(){
	int X,Y;
	cin >> X >> Y;
	if(X < Y){
		X+=3;
		if(X > Y)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else{
		Y+=3;
		if(Y > X)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
