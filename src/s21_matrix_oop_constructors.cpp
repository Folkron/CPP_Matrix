#include "s21_matrix_oop.h"

// standart constructor
S21Matrix::S21Matrix() : S21Matrix(1, 1) {}

// parametrized constructor
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 1 || cols < 1) {
    throw std::invalid_argument(
        "CreationError: Matrix sizes should be equal 1 or greater");
  } else {
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_];
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = 0;
      }
    }
  }
}

// copy constructor
S21Matrix::S21Matrix(const S21Matrix& o) : S21Matrix(o.rows_, o.cols_) {
  for (int i = 0; i < rows_; i++) delete[] matrix_[i];
  delete[] matrix_;

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

// move constructor
S21Matrix::S21Matrix(S21Matrix&& o) noexcept
    : rows_(o.rows_), cols_(o.cols_), matrix_(std::move(o.matrix_)) {
  o.matrix_ = NULL;
  o.rows_ = 0;
  o.cols_ = 0;
}

// destructor
S21Matrix::~S21Matrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; ++i) delete[] matrix_[i];
  }
  delete[] matrix_;
}