#include "Azn.cpp"
//purely for exponentiation

template <class T, size_t MAXSIZE> struct Matrix {
  int size;
  T data[MAXSIZE][MAXSIZE];

  Matrix(int size = MAXSIZE) : size(size) {
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        data[i][j] = 0;
  }

  T* operator[](int row) {
    return data[row];
  }

  Matrix operator*(const Matrix & other) const {
    Matrix ans = *this;
    return ans *= other;
  }

  Matrix& operator*=(const Matrix & other) {
    static T temp[MAXSIZE][MAXSIZE];
    for (int i = 0; i < size; i++)
      for (int j = 0, k; j < size; j++)
        for (k = 0, temp[i][j] = 0; k < size; k++)
          temp[i][j] += data[i][k] * other.data[k][j];
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        data[i][j] = temp[i][j];
    return *this;
  }

  Matrix operator^(long long exponent) const {
    Matrix ans = *this;
    return ans ^= exponent;
  }

  Matrix& operator^=(long long expon) {
    Matrix temp = *this;
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        data[i][j] = 0;
    for (int i = 0; i < size; i++) data[i][i] = 1;
    for ( ; expon > 0; expon >>= 1) {
      if (expon & 1) * this *= temp;
      temp *= temp;
    }
    return *this;
  }
} ;