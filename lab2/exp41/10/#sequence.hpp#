#ifndef SEQUENCE_HPP_
#define SEQUENCE_HPP_

class sequence
{
private:
  int value_;

  int const step_;

public:
  sequence(int start, int step ) : value_(start), step_(step) {}
 
  sequence(int start) : value_(start), step_(1) {}

  sequence() : value_(0), step_(1) {}

  int operator()() {
    int result(value_);

    value_ = value_ + step_;

    return result;
  }

};

#endif
