/* Copyright 2019 Jeremy S Lewis CSCE240 Dynamic Array */
/* Modified by Nicholas Knight */
#ifndef _MATRIX_CC_  //NOLINT
#define _MATRIX_CC_  //NOLINT

template <class T>
Matrix<T>::Matrix() : m_(nullptr), rows_(0), cols_(0) {}

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols) :
    rows_(rows), cols_(cols) {
  assert(rows > 0);
  assert(cols > 0);

  m_ = new T *[rows_];
  for (unsigned int i = 0; i < rows_; ++i)
    m_[i] = new T[cols_];
}

template <class T>
Matrix<T>::Matrix(const Matrix<T>& that) {
  m_ = new T *[rows_];
  for (unsigned int i = 0; i < that.rows_; ++i) {
    m_[i] = new T[that.cols_];
      for (unsigned int j = 0; j < that.cols_; ++j)
        m_[i][j] = that.m_[i][j];
  }
}

  /* Destructor: Required For Any Points
   *   Cleans up memory to avoid leaks
   */
  template <class T>
  Matrix<T>::~Matrix() {
    if (m_) {
      for (unsigned int i = 0; i < rows_; ++i)
        delete [] m_[i];
      delete [] m_;
    }
  }

  /* Accessor: 1 Point
   *   Precondition(s):
   *   - Parameter row is less than rows in matrix
   *   - Parameter col is less than cols in matrix
   *   Does what you would expect.
   */
  template <class T>
  T Matrix<T>::Get(unsigned int row, unsigned int col) const {
    return m_[row][col];
  }

  /* Assignment Op: 2 Points
   *   Precondition(s):
   *   - lhs rows must equal rhs rows
   *   - lhs cols must equal rhs cols
   *   Performs deep copy.
   */
  template <class T>
  const Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
    rows_ = rhs.rows_;
    cols_ = rhs.cols_;
    m_ = new T *[rows_];
    for (unsigned int i = 0; i < rows_; ++i) {
      m_[i] = new T[cols_];
      for (unsigned int j = 0; j < cols_; ++j)
        m_[i][j] = rhs.m_[i][j];
    }
    return *this;
  }

  /* Times Equals Op: 2 Points
   *   Returns calling object with matrix scaled by rhs.
   */
  template <class T>
  const Matrix<T>& Matrix<T>::operator*=(T rhs) {
    for (unsigned int i = 0; i < this->rows_; ++i)
      for (unsigned int j = 0; j < this->cols_; j++)
        m_[i][j] = m_[i][j] * rhs;
    return *this;
  }

  /* Add Op: 2 points
   *   Returns the sum of calling object's matrix and rhs's matrix as a new
   *   object.
   * Precondition(s):
   *   - lhs rows must equal rhs rows
   *   - lhs cols must equal rhs cols
   */
  template <class T>
  const Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const {
    Matrix<T> m2;
    m2.rows_ = rhs.rows_;
    m2.cols_ = rhs.cols_;
    m2.m_ = rhs.m_;
    for (unsigned int i = 0; i < this->rows_; ++i)
      for (unsigned int j = 0; j < this->cols_; j++)
        m2.m_[i][j] = rhs.m_[i][j] + m_[i][j];
    return m2;
  }

#include <matrix.h>

#endif
