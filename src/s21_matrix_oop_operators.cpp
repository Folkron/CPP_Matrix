#include "s21_matrix_oop.h"

S21Matrix& S21Matrix::operator=(const S21Matrix& o) {
  if (this != &o) {
    for (int i = 0; i < rows_; i++) delete[] matrix_[i];
    delete[] matrix_;

    rows_ = o.rows_;
    cols_ = o.cols_;
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_];
    }
    for (int i = 0; i < o.rows_; i++) {
      for (int j = 0; j < o.cols_; j++) {
        matrix_[i][j] = o.matrix_[i][j];
      }
    }
  }
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& o) { return EqMatrix(o); }

S21Matrix S21Matrix::operator+(const S21Matrix& o) {
  S21Matrix res(*this);
  res.SumMatrix(o);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& o) {
  S21Matrix res(*this);
  res.SubMatrix(o);
  return res;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& o) {
  SumMatrix(o);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& o) {
  SubMatrix(o);
  return *this;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix res(*this);
  res.MulNumber(num);
  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix& o) {
  S21Matrix res(*this);
  res.MulMatrix(o);
  return res;
}

S21Matrix operator*(double num, S21Matrix& o) { return o * num; }

S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& o) {
  MulMatrix(o);
  return *this;
}

double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
    throw std::out_of_range("Index is outside the matrix");
  } else {
    return matrix_[i][j];
  }
}