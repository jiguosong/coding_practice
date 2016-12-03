#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>

#include <iostream>

#include "helloboost.h"

int helloboost::helloboostExample ()
{
  boost::geometry::model::d2::point_xy<int> p1(1, 1), p2(2, 2);
  std::cout << "Distance p1-p2 is: " << boost::geometry::distance(p1, p2) << std::endl;
  return 0;
}
