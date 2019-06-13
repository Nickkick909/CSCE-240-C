// Copyright Nicholas Knight 2019

#include <mean.h>

namespace csce240 {

  Mean::Mean() : std::vector<double>() {/* empty*/}
  Statistic::~Statistic() {}
  Mean::~Mean() { }
  /* Stores data (datum) such than an average may be calculated.
   * - NOTE: You do not necessarily need to store each datum.
   */
  void Mean::Collect(double datum) {
      push_back(datum);
  }

  /* Returns the mean of the data (datum) from the Collect method.
   */
  double Mean::Calculate() const {
      double sum = 0.0;
      for (size_t i = 0; i < size(); ++i) {
          sum += at(i);
      }
      if (size() > 0)
        return sum / size();
      return 0.0;
  }


}  // namespace csce240
