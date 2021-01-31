#include <bits/stdc++.h>
using namespace std;

int main(){
	string S;
	cin >> S;
	if(S[(int)S.size() - 1] == 's'){
		cout << S + "es" << endl;
	}
	else cout << S + "s" << endl;
}
