#include <iostream>
#include <share_point.hpp>

int main() {
  Shared_point<int> p1(new int(9));
  Shared_point<int> p2(p1);
  return 0;
}