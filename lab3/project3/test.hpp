#ifndef TEST_HPP_
#define TEST_HPP_

#include <exception>
#include <iostream>
#include <ostream>

#define TEST_STRINGIFY(x) #x

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

#define TEST(x)								\
  try {									\
    test_run(x, TEST_STRINGIFY(x), __FILE__, __LINE__);			\
  }									\
  catch(std::exception const& ex)					\
    {									\
      test_exception(ex, TEST_STRINGIFY(x), __FILE__, __LINE__);	\
    }

#endif
