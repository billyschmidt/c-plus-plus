#include <iostream>
#include <istream>
#include <ostream>
#include <string>

void ignore_line();
int prompted_read(std::string prompt);
void print_result(int count, int sum);

int main()
{
  int sum(0);
  int count(0);

  while (std::cin)
    {
      int x(prompted_read("Value: "));
      if (std::cin)
	{
	  sum = sum + x;
	  ++count;
	}
    }
  print_result(count, sum);
}

int prompted_read(std::string prompt)
{
  std::cout << prompt;
  int x(-1);
  std::cin >> x;
  ignore_line();
  return x;
}

void ignore_line()
{
  char c;
  while (std::cin.get(c) and c != '\n')
    /*empty*/;
}

void print_result(int count, int sum)
{
  if (count == 0)
    {
      std::cout << "no data\n";
      return;
    }

  std::cout << "\ncount = " << count;
  std::cout << "\nsum   = " << sum;
  std::cout << "\nmean  = " << sum/count << '\n';
}
