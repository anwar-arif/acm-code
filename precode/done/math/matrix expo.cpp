#include <bits/stdc++.h>
using namespace std;

/*
    |  f(n+k) | = M^k * |  f(n)  |
    | f(n+k-1)|         | f(n-1) |
*/

/// if we know the first d value of function then k = n - d

struct matrix {
  int v[5][5];
  int row, col;
};

/// multiplies two matrices and returns the result

matrix multiply(matrix a, matrix b) {

  matrix r;

  r.row = a.row;
  r.col = b.col;

  for (int i = 1; i <= r.row; i++) {

    for (int j = 1; j <= r.col; j++) {

      int sum = 0;

      for (int k = 1; k <= a.col;  k++) {

        sum += a.v[i][k] * b.v[k][j];
      }

      r.v[i][j] = sum;

    }

  }
  return r;
}

/// returns mat^p
matrix power(matrix mat, int p) {

  if (p == 1) return mat;

  if (p % 2 == 1){

      return multiply(mat, power(mat, p - 1));
  }
  else{
      matrix ret = power(mat, p / 2);
      ret = multiply(ret, ret);
      return ret;
  }
}

/// complexity : O( d^3 * log(n) ) ; d = dimension of sqr mat M ; n for f(n)

int main(){

    return 0;
}
