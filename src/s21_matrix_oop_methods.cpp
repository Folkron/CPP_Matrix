#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& o) {
  bool is_eq = true;
  if (rows_ != o.rows_ || cols_ != o.cols_) {
    is_eq = false;
  }
  if (is_eq) {
    for (int i = 0; i < rows_ && is_eq; i++) {
      for (int j = 0; j < cols_ && is_eq; j++) {
        if (matrix_[i][j] != o.matrix_[i][j]) {
          is_eq = false;
        }
      }
    }
  }
  return is_eq;
}

void S21Matrix::SumMatrix(const S21Matrix& o) {
  if (rows_ != o.rows_ || cols_ != o.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] += o.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& o) {
  if (rows_ != o.rows_ || cols_ != o.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] -= o.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& o) {
  if (rows_ != o.rows_ || cols_ != o.cols_) {
    throw std::out_of_range(
        "Incorrect input, columns of first matrix must be equal to the rows of "
        "the second matrix");
  }
  S21Matrix res(rows_, o.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < o.cols_; j++) {
      for (int k = 0; k < o.rows_; k++) {
        res.matrix_[i][j] += matrix_[i][k] * o.matrix_[k][j];
      }
    }
  }
  *this = res;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix res(cols_, rows_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      res.matrix_[i][j] = matrix_[j][i];
    }
  }
  return res;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::out_of_range("Exception: matrix must be square");
  } else {
    double det = 0;
    if (rows_ == 1) {
      det = matrix_[0][0];
    } else if (rows_ == 2) {
      det = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
    } else {
      for (int i = 0; i < cols_; i++) {
        S21Matrix m(minor(0, i));
        det += pow(-1, i) * matrix_[0][i] * m.Determinant();
      }
    }
    return det;
  }
}

S21Matrix S21Matrix::minor(int l, int k) {
  S21Matrix m(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (i < l && j < k) {
        m.matrix_[i][j] = matrix_[i][j];
      }
      if (i < l && j > k) {
        m.matrix_[i][j - 1] = matrix_[i][j];
      }
      if (i > l && j < k) {
        m.matrix_[i - 1][j] = matrix_[i][j];
      }
      if (i > l && j > k) {
        m.matrix_[i - 1][j - 1] = matrix_[i][j];
      }
    }
  }
  return m;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::out_of_range("Exception: matrix must be square");
  } else {
    S21Matrix comp(rows_, cols_);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        comp.matrix_[i][j] = pow(-1, i + j) * minor(i, j).Determinant();
      }
    }
    return comp;
  }
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  if (det == 0) throw std::out_of_range("Exception: matrix must be square");

  S21Matrix inv(rows_, cols_);
  inv = CalcComplements();
  inv = inv.Transpose();
  inv.MulNumber(1.0 / det);
  return inv;
}

void S21Matrix::set_matrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      std::cin >> matrix_[i][j];
    }
  }
}

void S21Matrix::print_matrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      std::cout << matrix_[i][j] << " ";
    }
    std::cout << '\n';
  }
}