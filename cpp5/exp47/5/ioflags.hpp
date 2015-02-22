#ifndef IOFLAGS_HPP_
#define IOFLAGS_HPP_

/** save and restore I/O stream flags */

class ioflags
{
public:
  ioflags(std::basic_ios<char>& stream)
    : stream_(stream), flags_(stream.flags())
  {/* empty */}
  
  ~ioflags() 
  {
    stream_.flags(flags_); 
  }
private:
  std::basic_ios<char>& stream_;
  std::ios_base::fmtflags flags_;
};

#endif
