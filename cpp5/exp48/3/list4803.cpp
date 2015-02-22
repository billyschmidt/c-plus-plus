/**
 * Bill Schmidt
 * 4159697
 * writing an explicit specialization for point <double>
 * and demonstrating that the proper template was used
 * to create the individual objects
 * 
 */

#include <iostream>
#include <ostream>

// begin class template
template<class T>
class point
{
public:
  // typedef for easier code management
  typedef T value_type;
  
  point()
    : x_(), y_()
  {
    // print default constrcutor message
    std::cout << "Default point<>() used.\n";
  }
  
  point(T const& x, T const& y)
    : x_(x), y_(y)
  {}
    
  T const& x() const
  {
    return x_;
  }
  
  T const& y() const 
  {
    return y_; 
  }
  
  // move to this position
  void move_absolute(T const& x, T const& y) 
  {
    x_ = x;
    y_ = y;
  }
  
  // move relative to axis
  void move_relative(T const& dx, T const& dy) 
  {
    x_ += dx;
    y_ += dy;
  }
  
private:
  // private members
  T x_;
  T y_;
};

// specialization template for doubles
// will print statement within constructor
template<>
class point<double>
{
public:
  typedef double value_type;
  
  point()
    : x_(), y_()
  {
    // display use of specialized template
    std::cout << "Specialization point<double> used.\n"; 
  }
  
  point(double  x, double y)
    : x_(x), y_(y)
  {}
  
  double x() const 
  {
    return x_;
  }
  
  double y() const
  {
    return y_; 
  }
  
  void move_absolute(double x, double y) 
  {
    x_ = x;
    y_ = y;
  }

  void move_relative(double dx, double dy) 
  {
    x_ += dx;
    y_ += dy;
  }
private:
  double x_;
  double y_;
};

int main()
{
  // create objects and call move function

  // should use default
  point<int> test_int;
  point<short> test_short;

  // should use specialization
  point<double> test_double;
  point<double> test_double_02;
  point<double> test_double_03;

  // call move.absolute
  test_int.move_absolute(234, 345);
  test_short.move_absolute(60.987, 43.044);

  // doubles
  test_double.move_absolute(54.123, 87.234);
  test_double.move_absolute(54.123, 87.234);
  test_double_02.move_absolute(-34, 345.45);
  test_double_03.move_absolute(1234, -576);
}
