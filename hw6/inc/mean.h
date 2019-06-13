// Copyright Nicholas Knight 2019
#ifndef _MEAN_H_  //NOLINT  
#define _MEAN_H_  //NOLINT
/* This class inherits from the Statistic class such that it may be used
 * polymorphically.
 */

#include <statistic.h>
#include <vector>

namespace csce240 {

class Mean : public std::vector<double>, public Statistic {
 public:
  Mean();
  ~Mean();
  /* Stores data (datum) such than an average may be calculated.
   * - NOTE: You do not necessarily need to store each datum.
   */
  void Collect(double datum);

  /* Returns the mean of the data (datum) from the Collect method.
   */
  double Calculate() const;
};

}  // namespace csce240
#endif //NOLINT
