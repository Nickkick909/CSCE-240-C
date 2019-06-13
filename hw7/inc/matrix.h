/* Copyright 2019 Jeremy S Lewis CSCE240 Templated Dynamic Array */
/* Modified by Nicholas Knight */
#ifndef _MATRIX_H_  //NOLINT
#define _MATRIX_H_  //NOLINT
#include <cassert>
// using assert
#include <ostream>


class MatrixTester;

template <class T>
class Matrix {
 public:
  friend class MatrixTester;

  Matrix();  // for testing, useless in practice
  Matrix(unsigned int rows, unsigned int cols);


  /* Copy Constructor: 2 Points
   *   Performs deep copy.
   */
  Matrix(const Matrix<T>& that);


  /* Destructor: Required For Any Points
   *   Cleans up memory to avoid leaks
   */
  ~Matrix();


  /* Accessor: 1 Point
   *   Precondition(s):
   *   - Parameter row is less than rows in matrix
   *   - Parameter col is less than cols in matrix
   *   Returns matrix element from row and col. Type is same as matrix type.
   */
  T Get(unsigned int row, unsigned int col) const;


  /* Assignment Op: 2 Points
   *   Precondition(s):
   *   - lhs rows must equal rhs rows
   *   - lhs cols must equal rhs cols
   *   Performs deep copy.
   */
  const Matrix<T>& operator=(const Matrix<T>& rhs);


  /* Times Equals Op: 1 Point
   *   Returns calling object with matrix scaled by rhs.
   *   Parameter:
   *    - rhs will be the same type as the matrix
   */
  const Matrix<T>& operator*=(T rhs);


  /* Add Op: 1 Point
   *   Returns the sum of calling object's matrix and rhs's matrix as a new
   *   object.
   * Precondition(s):
   *   - lhs rows must equal rhs rows
   *   - lhs cols must equal rhs cols
   */
  const Matrix<T> operator+(const Matrix<T>& rhs) const;


 private:
    T **m_;
    unsigned int rows_;
    unsigned int cols_;
};

#include <matrix.cc>  //NOLINT
#endif  //NOLINT
