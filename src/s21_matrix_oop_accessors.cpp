#include "s21_matrix_oop.h"

int S21Matrix::GetRows() const { return rows_; }
int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows < 1) {
    throw std::invalid_argument(
        "CreationError: Matrix sizes should be equal 1 or greater");
  }
  if (rows != rows_) {
    S21Matrix result(rows, cols_);
    for (int i = 0; i < (rows_ < rows ? rows_ : rows); ++i) {
      for (int j = 0; j < cols_; ++j) {
        result.matrix_[i][j] = matrix_[i][j];
      }
    }
    *this = std::move(result);
  }
}

void S21Matrix::SetCols(int cols) {
  if (cols < 1) {
    throw std::invalid_argument(
        "CreationError: Matrix sizes should be equal 1 or greater");
  }
  if (cols != cols_) {
    S21Matrix result(rows_, cols);
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < (cols_ < cols ? cols_ : cols); ++j) {
        result.matrix_[i][j] = matrix_[i][j];
      }
    }
    *this = std::move(result);
  }
}
