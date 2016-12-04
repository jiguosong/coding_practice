#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/lambda/lambda.hpp>

#include <iostream>
#include <iterator>
#include <algorithm>
#include <memory>

#include <iostream>
#include <utility>
#include <vector>
#include <string>

#include "helloboost.h"

int helloboost::helloboostExample ()
{
  boost::geometry::model::d2::point_xy<int> p1(1, 1), p2(2, 2);
  std::cout << "Distance p1-p2 is: " << boost::geometry::distance(p1, p2) << std::endl;

  std::string str = "Hello";
  std::vector<std::string> v;

  // uses the push_back(const T&) overload, which means
  // we'll incur the cost of copying str
  v.push_back(str);
  std::cout << "After copy, str is \"" << str << "\"\n";

  // uses the rvalue reference push_back(T&&) overload,
  // which means no strings will be copied; instead, the contents
  // of str will be moved into the vector.  This is less
  // expensive, but also means str might now be empty.

  v.push_back(std::move(str));
  std::cout << "After move, str is \"" << str << "\"\n";

  std::cout << "The contents of the vector are \"" << v[0]
									   << "\", \"" << v[1] << "\"\n";

  return 0;
}
#include <iostream>
#include <utility>
#include <vector>
#include <string>
