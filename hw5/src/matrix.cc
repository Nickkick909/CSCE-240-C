// Copyright Nicholas Knight 2019
#include <matrix.h>

Matrix::Matrix() : m_(nullptr), rows_(0), cols_(0) {}

Matrix::Matrix(unsigned int rows, unsigned int cols) :
    rows_(rows), cols_(cols) {
  assert(rows > 0);  // assert preconditions are true
  assert(cols > 0);  // assert preconditions are true

  m_ = new double *[rows_];  // create array of double pointers
  for (unsigned int i = 0; i < rows_; ++i)
    m_[i] = new double[cols_];  // create array of doubles
}

Matrix::Matrix(const Matrix& that) {
  m_ = new double *[rows_];
  for (unsigned int i = 0; i < that.rows_; ++i) {
    m_[i] = new double[that.cols_];
      for (unsigned int j = 0; j < that.cols_; ++j)
        m_[i][j] = that.m_[i][j];
  }
}

  /* Destructor: Required For Any Points
   *   Cleans up memory to avoid leaks
   */
  Matrix::~Matrix() {
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
  double Matrix::Get(unsigned int row, unsigned int col) const {
    return m_[row][col];
  }

  /* Assignment Op: 2 Points
   *   Precondition(s):
   *   - lhs rows must equal rhs rows
   *   - lhs cols must equal rhs cols
   *   Performs deep copy.
   */
  const Matrix& Matrix::operator=(const Matrix& rhs) {
    // for (unsigned int i = 0; i < this->rows_; ++i)
    //   for (unsigned int j = 0; j < this->cols_; j++)
    //     m_[i][j] = rhs.m_[i][j];
    // return *this;
    rows_ = rhs.rows_;
    cols_ = rhs.cols_;
    m_ = new double *[rows_];
    for (unsigned int i = 0; i < rows_; ++i) {
      m_[i] = new double[cols_];
      for (unsigned int j = 0; j < cols_; ++j)
        m_[i][j] = rhs.m_[i][j];
    }
    return *this;
  }

  /* Times Equals Op: 2 Points
   *   Returns calling object with matrix scaled by rhs.
   */
  const Matrix& Matrix::operator*=(double rhs) {
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
  const Matrix Matrix::operator+(const Matrix& rhs) const {
    Matrix m2;
    m2.rows_ = rhs.rows_;
    m2.cols_ = rhs.cols_;
    m2.m_ = rhs.m_;
    for (unsigned int i = 0; i < this->rows_; ++i)
      for (unsigned int j = 0; j < this->cols_; j++)
        m2.m_[i][j] = rhs.m_[i][j] + m_[i][j];
    return m2;
  }
