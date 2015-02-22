// class for generating unique id
class generate_id
{
public:
  generate_id() : counter_(0) {}
  long next();

private:
  short counter_;
  static short prefix_;
  static long int const max_counter_ = 3653;
};
