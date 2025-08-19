#ifndef __S21MATRIX_OOP_H__
#define __S21MATRIX_OOP_H__

#include <math.h>

#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  // accessors
  void SetRows(int rows);
  void SetCols(int cols);
  int GetRows() const;
  int GetCols() const;
  // constructors
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& o);
  S21Matrix(S21Matrix&& o) noexcept;
  ~S21Matrix() noexcept;
  // operators overloads
  S21Matrix& operator=(const S21Matrix& o);
  double& operator()(int i, int j);
  bool operator==(const S21Matrix& o);
  S21Matrix operator+(const S21Matrix& o);
  S21Matrix& operator+=(const S21Matrix& o);
  S21Matrix operator-(const S21Matrix& o);
  S21Matrix& operator-=(const S21Matrix& o);
  S21Matrix operator*(const S21Matrix& o);
  S21Matrix operator*(const double num);
  friend S21Matrix operator*(double num, S21Matrix& o);
  S21Matrix& operator*=(const double num);
  S21Matrix& operator*=(const S21Matrix& o);
  // methods
  bool EqMatrix(const S21Matrix& o);
  void SumMatrix(const S21Matrix& o);
  void SubMatrix(const S21Matrix& o);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& o);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // Other
  S21Matrix minor(int l, int k);
  void set_matrix();
  void print_matrix();
};

#endif