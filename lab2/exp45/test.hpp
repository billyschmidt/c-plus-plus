// test header file

#ifndef TEST_HPP_
#define TEST_HPP_

#include <exception>
#include <iostream>
#include <ostream>

#define test_stringify(x) #x

inline void test_failed(char const* expr, char const* file, int line)
{
  std::cerr << file << ", line " << line << ": test failed: " << expr << '\n';
}

inline void test_run(bool condition, char const* expr, char const* file, int line)
{
  if (not condition)
    test_failed(expr, file, line);
}

inline void test_exception(std::exception const& ex, char const* expr, char const* file, int line)
{
  std::string msg( expr );
  msg += " threw an exception: ";
  msg += ex.what();
  test_failed(msg.c_str(), file, line);
}

#define test(x)								\
  try {									\
    test_run(x, test_stringify(x), __FILE__, __LINE__);			\
  }									\
  catch(std::exception const& ex)					\
    {									\
      test_exception(ex, test_stringify(x), __FILE__, __LINE__);	\
    }

#endif
