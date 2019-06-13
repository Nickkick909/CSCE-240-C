// Copyright Nicholas Knight 2019
#ifndef _MEDIAN_H_  //NOLINT  
#define _MEDIAN_H_  //NOLINT
/* This class inherits from the Statistic class such that it  may be used
 * polymorphically.
 */
#include <statistic.h>
#include <vector>

namespace csce240 {

class Median:  public std::vector<double>, public Statistic{
 public:
  Median();
  ~Median();
  /* Stores data (datum) such than the median may be determined.
   */
  void Collect(double datum);

  /* Calculates the median of the data (datum) from the Collect method.
   */
  double Calculate() const;
};

}  // namespace csce240
#endif //NOLINT
