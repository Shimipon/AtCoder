#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int main(){
	int H, W;
    cin >> H >> W;
    string s[H];
    for(int i=0;i<H;i++){
        cin >> s[i]; 
    }
    int check = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(s[i][j] == '#'){
                int ok = 0;
                if(i > 0){
                    if(s[i-1][j] == '#')ok = 1;
                }
                if(j > 0){
                    if(s[i][j-1] == '#')ok = 1;
                }
                if(i < H - 1){
                    if(s[i+1][j] == '#')ok = 1;
                }
                if(j < W - 1){
                    if(s[i][j+1] == '#')ok = 1;
                }
                if(!ok)check = 1;
            }
        }
    }
    if(check) cout << "No" << endl;
    else cout << "Yes" << endl;
}