// Copyright Nicholas Knight 2019

#include "gradebook.h" //NOLINT


vector<double> grades;

  /* Adds a new grade to the gradebook instance, increasing size by 1.
   */
  GradeBook::GradeBook() {
      this->grades.clear();
  }

  void GradeBook::Add(double grade) {
      grades.push_back(grade);
  }


  /* Returns the grade at the supplied index. When that index is out of range, a
   * value of NAN (from cmath) is returned.
   */
  double GradeBook::Get(size_t index) const {
    if (index > grades.size())
        return NAN;
    return grades.at(index);
  }


  /* Adds two GradeBook instances together and returns their join as a new
   * object.
   * Order is maintained by adding the calling instance's grades to the new
   * Gradebook instance, followed by the parameter GradeBook's instances.
   */
  const GradeBook GradeBook::Add(const GradeBook& that) const {
      GradeBook newGrades;
      for (size_t i = 0; i < grades.size(); ++i)
        newGrades.Add(grades[i]);
      for (size_t i = 0; i< that.GetSize(); ++i)
        newGrades.Add(that.Get(i));
      return newGrades;
  }


  /* Returns the average of all grades stored in GradeBook instance, or NAN(from
   * cmath) if the the GradeBook instance is empty.
   */
  double GradeBook::GetGPA() const {
      if (grades.size() == 0)
        return NAN;
      double sum = 0;
      for (size_t i = 0; i < grades.size(); ++i)
        sum += grades[i];
      return sum/grades.size();
  }


  /* Returns the max grade in the GradeBook or NAN if the calling instance is
   * empty.
   */
  double GradeBook::GetMax() const {
      if (grades.size() == 0)
        return NAN;
      double max = -1;
      for (size_t i = 0; i < grades.size(); ++i)
        if (grades[i] > max)
            max = grades[i];
      return max;
  }


  /* Returns the number of grades currently stored by the GradeBook.
   */
  const size_t GradeBook::GetSize() const {
      return grades.size();
  }


  /* Returns true when two GradeBook instances have the same average grade
   * value; returns false otherwise. An empty instance is treated as having an
   * average grade value of -infinity.
   * Equality should be true if the grades are within 0.00001 of each other.
   */
  bool GradeBook::Equals(const GradeBook& that) const {
      double error = 0.00001;
      GradeBook gradesGB;
      for (size_t i = 0; i < grades.size(); ++i)
        gradesGB.Add(grades[i]);
      if (((that.GetGPA() - gradesGB.GetGPA()) < error)
        && ((that.GetGPA() - gradesGB.GetGPA()) > -error))
        return true;
      return false;
  }


  /* Returns true when the calling instance has a smaller grade average than the
   * paramter instance's average. If they are even, it compares their max
   * grades. An empty instance is treated as having an average grade value of
   * -infinity.
   */
  bool GradeBook::LessThan(const GradeBook& that) const {
      double error = 0.00001;
      GradeBook gradesGB;
      for (size_t i = 0; i < grades.size(); ++i)
        gradesGB.Add(grades[i]);
      if (gradesGB.GetSize() == 0 || that.GetSize() == 0)
        return -INFINITY;
      if (((that.GetGPA() - gradesGB.GetGPA()) < error)
        && ((that.GetGPA() - gradesGB.GetGPA()) > -error)) {
          if (gradesGB.GetMax() < that.GetMax())
            return true;
          else
            return false;
      }
      if (gradesGB.GetGPA() < that.GetGPA())
        return true;

      return false;
  }

