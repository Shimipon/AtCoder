#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int check = 0;
    for(int i=1;i<=N;i++){
        if(i % 4 == 0 && (N - i) % 7 == 0){
            check = 1;
        } 
    }
    if(check) cout << "Yes" << endl;
    else cout << "No" << endl;
}