// Bill Schmidt
// 4159697
// adding print member function to each class

#include <iostream>
#include <ostream>
#include <string>

// begin work class
class work
{
public:
  // constructors
  work() : id_(), title_() {}
  work(std::string const& id, std::string const& title) : id_(id), title_(title) {}
  
  // destructor 
  virtual ~work() {}

  // public id and title data members
  std::string const& id()    const { return id_; }
  std::string const& title() const { return title_; }

  // new print member function (use virtual prefix)
  virtual void print(std::ostream& out) const {}

private:
  // data members private to work
  std::string id_;
  std::string title_;
};


// begin class book
class book : public work
{
public:
  // constructors
  book() : author_(), pubyear_(0) {}
  book(std::string const& id, std::string const& title, std::string const& author, int pubyear)
    : work(id, title), author_(author), pubyear_(pubyear) {}
  
  
  std::string const& author() const { return author_; }
  int pubyear()const { return pubyear_; }

  // virtual print func
  virtual void print(std::ostream& out) const
  {
    out << author() << ", " << title() << ", " << pubyear() << ".";
  }
  
private:
  // private data to book
  std::string author_;
  int pubyear_;
};


// beign class periodical
class periodical : public work
{
public:
  // constructors
  periodical() : volume_(0), number_(0), date_() {}
  periodical(std::string const& id, std::string const& title, int volume, int number, std::string const& date)
    : work(id, title), volume_(volume), number_(number), date_(date) {}
  
  // public data members
  int volume()const { return volume_; }
  int number()const { return number_; }
  std::string const& date() const { return date_; }

  // print function  
  virtual void print(std::ostream& out) const
  {
    out << title() << ", " << volume() << '(' << number() << "), " << date() << ".";
  }
  
private:
  // private data
  int volume_;
  int number_;
  std::string date_;
};

int main()
{
  book test_01("001", "This is fun!", "Bill Schmidt", 1984);
  periodical test_02("002", "C++ is the best ever!", 03, 35, "Oct. 12th 2010");

  // testing print functions:
  std::cout << "testing print functions: \n";
  test_01.print(std::cout); 
  std::cout << '\n';
  test_02.print(std::cout);
  std::cout << "\n\n";
}
