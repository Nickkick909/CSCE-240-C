// Copyright Nicholas Knight 2019

#include <median.h>

namespace csce240 {

  Median::Median() : std::vector<double>() {/* empty*/}
  Statistic::~Statistic() {}
  Median::~Median() { }
  /* Stores data (datum) such than the median may be determined.
   */
  void Median::Collect(double datum) {
    push_back(datum);
    for (size_t i = 0; i < size() - 1; ++i) {
      for (size_t j = 0; j < size() - i - 1; ++j) {
        if (at(j) > at(j +1)) {
          double tmp = at(j);
          at(j) = at(j + 1);
          at(j + 1) = tmp;
        }
      }
    }
  }

  /* Calculates the median of the data (datum) from the Collect method.
   */
  double Median::Calculate() const {
    // vector sortedVector;
    // for (size_t j = 0; size() > sortedVector.size(); ++j) {
    //     double min = INFINITY;

    //     for (size_t i = j; i < size(); ++i){
    //         if (at(i) < min) {
    //             min = at(i);
    //         }
    //     }
    //     sortedVector.push_back(min);
    // }
    if (size()  % 2 == 0)
      return (at((size() / 2)-1) + at((size() / 2) )) / 2;
    else
      return at((size() / 2));
  }



}  // namespace csce240
