// Copyright Nicholas Knight 2019
#ifndef _STATISTIC_H_  //NOLINT  
#define _STATISTIC_H_  //NOLINT
/* This is an abstract base class which Statistic classes extend.
 */

#include <vector>
#include <iostream>
namespace csce240 {


class Statistic {
 public:
  /* Not a pure virtual so that children may not override if unused
   */
  virtual ~Statistic();

  /* Defined by children
   */
  virtual void Collect(double) = 0;

  /* Defined by children
   */
  virtual double Calculate() const = 0;
};

}  // namespace csce240
#endif //NOLINT