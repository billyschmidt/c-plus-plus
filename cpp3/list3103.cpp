/** Listing 31-3. Using a Class and its Members */
#include <cmath>
#include <iostream>
#include <ostream>

struct point
{
  double x;
  double y;

  /// Distance to the origin.
  double distance()
  {
    return std::sqrt(x*x + y*y);
  }

  /// Angle relative to x-axis.
  double angle()
  {
    return std::atan2(y, x);
  }

  /// Add an offset to x and y.
  void offset(double off)
  {
    offset(off, off);
  }

  /// Add an offset to x and an offset to y
  void offset(double  xoff, double yoff)
  {
    x = x + xoff;
    y = y + yoff;
  }

  /// Scale x and y.
  void scale(double mult)
  {
    this->scale(mult, mult);
  }

  /// Scale x and y.
  void scale(double xmult, double ymult)
  {
    this->x = this->x * xmult;
    this->y = this->y * ymult;
  }
};

int main()
{
  point origin, unity;
  origin.x = 0;
  origin.y = 0;
  unity.x = 1;
  unity.y = 1;

  std::cout << "origin = (" << origin.x << ", " << origin.y << ")\n";
  std::cout << "unity  = (" << unity.x  << ", " << unity.y  << ")\n";

  point test;
  test.x = 8;
  test.y = 12;
  test.distance();
  test.angle();
  test.offset(3, 4);
    
  std::cout << "test distance = (" << test.distance() << ")\n";
  std::cout << "test angle =    (" << test.angle()    << ")\n";
  
  // std::cout << "test offset =   (" << test.offset(3, 4)  << ")\n";
  std::cout << "test offset  = (" << test.x  << ", " << test.y  << ")\n";
}
