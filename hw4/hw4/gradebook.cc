// Copyright Nicholas Knight 2019
#include "../hw4/gradebook.h" // NOLINT


void GradeBook::Add(double grade) {
  grades_.push_back(grade);
}
double GradeBook::Get(size_t index) const {
  return index < grades_.size() ? grades_[index] : NAN;
}
  // Returns a new GradeBook instance with the floating point parameter
  const GradeBook GradeBook::operator+(double rhs) const {
    GradeBook returnGrades;

    for (size_t i=0; i< grades_.size(); ++i)
      returnGrades.Add(grades_[i]);
    returnGrades.Add(rhs);
    return returnGrades;
  }


  // Adds two GradeBook instances together
  const GradeBook GradeBook::operator+(const GradeBook& rhs) const {
    GradeBook returnGrades;

    for (size_t i=0; i< grades_.size(); ++i)
      returnGrades.Add(grades_[i]);
    for (size_t i=0; i< rhs.grades_.size(); ++i)
      returnGrades.Add(rhs.Get(i));
    return returnGrades;
  }


  /* Returns true when two GradeBook instances have the same average grade
   * value; returns false otherwise. An empty instance is treated as having an
   * average grade value of -infinity.
   * Equality should be true if the grades' average are within 0.00001 of each
   * other.
   */
  bool GradeBook::operator==(const GradeBook& rhs) const {
    double sum1 = 0;
    for (size_t i = 0; i < grades_.size(); ++i)
      sum1 += grades_[i];

    double sum2 = 0;
    for (size_t i = 0; i < rhs.grades_.size(); ++i)
      sum2 += rhs.grades_[i];

    if (grades_.size() == 0)
      sum1 = -INFINITY;
    else
      sum1 = sum1 / grades_.size();
    if (rhs.grades_.size() == 0)
      sum2 = -INFINITY;
    else
      sum2 = sum2 / rhs.grades_.size();
    if ((sum1 - sum2 < 0.00001) && (sum2 - sum1 < 0.00001))
      return true;
    return false;
  }


  /* Returns true when the double parameter is equal to the average of all the
   * grades stored in calling GradeBook instance. Treat average as -INFINITY if
   * calling instance is empty.
   * Equality should be true if the grade's instance are within 0.00001 of
   * floating point parameter.
   */
  bool GradeBook::operator==(double rhs) const {
    double sum1 = 0;
    for (size_t i = 0; i < grades_.size(); ++i)
      sum1 += grades_[i];

    if (grades_.size() == 0)
      sum1 = -INFINITY;
    else
      sum1 = sum1 / grades_.size();

    if ((sum1 - rhs < 0.00001) && (rhs - sum1 < 0.00001))
      return true;
    return false;
  }


  /* Returns true when the calling instance has a smaller grade average than the
   * paramter instance's average. If they are even, it compares their max
   * grades. An empty instance is treated as having an average grade value of
   * -infinity.
   */
  bool GradeBook::operator<(const GradeBook& rhs) const {
    double sum1 = 0;
    for (size_t i = 0; i < grades_.size(); ++i)
      sum1 += grades_[i];

    double sum2 = 0;
    for (size_t i = 0; i < rhs.grades_.size(); ++i)
      sum2 += rhs.grades_[i];

    if (grades_.size() == 0)
      sum1 = -INFINITY;
    else
      sum1 = sum1 / grades_.size();
    if (rhs.grades_.size() == 0)
      sum2 = -INFINITY;
    else
      sum2 = sum2 / rhs.grades_.size();
    if (sum1 == sum2) {
      double max1 = 0;
      double max2 = 0;
      for (size_t i = 0; i < grades_.size(); ++i)
        if (grades_[i] > max1)
          max1 = grades_[i];
      for (size_t i = 0; i < rhs.grades_.size(); ++i)
        if (rhs.grades_[i] > max2)
          max2 = rhs.grades_[i];
      return max1 < max2;
      }
    return sum1 < sum2;
  }


  /* Returns true when the calling instance has a smaller grade average than the
   * floating point parameter.
   */
  bool GradeBook::operator<(double rhs) const {
    double sum1 = 0;
    for (size_t i = 0; i < grades_.size(); ++i)
      sum1 += grades_[i];

    if (grades_.size() == 0)
      sum1 = -INFINITY;
    else
      sum1 = sum1 / grades_.size();

    return sum1 < rhs;
  }


/* Returns a new GradeBook instance with the floating point parameter
 * appended.
 */
const GradeBook operator+(double lhs, const GradeBook& rhs) {
  GradeBook returnGradeBook;
  returnGradeBook = rhs;
  returnGradeBook.Add(lhs);
  return returnGradeBook;
}

/* Returns true when the double parameter is equal to the average of all the
 * grades stored in the GradeBook instance. Treat average as -INFINITY if
 * either GradeBook instance is empty.
 * Equality should be true if the grade's instance are within 0.00001 of
 * floating point parameter.
 */
bool operator==(double lhs, const GradeBook& rhs) {
  return rhs == lhs;
}

/* Returns true when the floating point parameter is less than the grade average
 * of the GradeBook parameter.
 */
bool operator<(double lhs, const GradeBook& rhs) {
  return !(rhs < lhs);
}
