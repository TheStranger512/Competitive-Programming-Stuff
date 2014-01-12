#include "Azn.cpp"

void gauss() {
  const double EPS = 1e-6;
  double mat[111][111];
  int cols, rows;
  if (cols > rows) {
    puts("NO UNIQUE SOLUTION");
    return;
  }
  for (int k = 0; k < cols; k++) {
    int piv = k, r, c;
    double val;
    for (r = k; r < rows; r++)
      if (abs(mat[r][k]) > abs(mat[piv][k]))
        piv = r;
    if (abs(mat[piv][k]) <= EPS) {
      puts("NO UNIQUE SOLUTION");
      return;
    }
    for (c = 0; c <= cols; c++)
      swap(mat[piv][c], mat[k][c]);
    for (c = 0, val = mat[k][k]; c <= cols; c++)
      mat[k][c] /= val;
    for (r = 0; r < rows; r++)
      if (r != k)
        for (c = 0, val = mat[r][k]; c <= cols; c++)
          mat[r][c] -= mat[k][c] * val;
    //plnarr(mat, 2, 3);
  }
  for (int r = cols; r < rows; r++) {
    double val = 0;
    for (int c = 0; c < cols; c++)
      val += mat[r][c] * mat[c][cols];
    val -= mat[r][cols];
    if (abs(val) > EPS) {
      puts("NO UNIQUE SOLUTION");
      return;
    }
  }
}