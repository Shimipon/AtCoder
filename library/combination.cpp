

// C[]にnCmを入れて処理を行うを繰り返す

int N, M;
N = 5;
M = 3;
int C[M];
// sにはN-1の値を、restにはMの値を引数として渡せばおけ
void recursive_comb(int s, int rest) {
  if (rest == 0) {
    
  } 
  else {
    if (s < 0) return;
    recursive_comb(s - 1, rest);
    indexes[rest - 1] = s;
    recursive_comb(s - 1, rest - 1);
  }
}