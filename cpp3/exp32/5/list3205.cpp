// adding const modifier to print funtion

#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <limits>
#include <locale>
#include <ostream>
#include <string>
#include <vector>

int compute_bmi(int height, int weight)
{
  return static_cast<int>(weight * 10000 / (height * height) + 0.5);
}

void skip_line(std::istream& in)
{
  in.ignore(std::numeric_limits<int>::max(), '\n');
}

struct record
{
  record() : height_(0), weight_(0), bmi_(0), sex_('?'), name_()
  {}

  bool read(std::istream& in, int num)
  {
    std::cout << "Name " << num << ": ";
    std::string name;
    if (not std::getline(in, name))
      return false;

    std::cout << "Height (cm): ";
    int height;
    if (not (in >> height))
      return false;
    skip_line(in);

    std::cout << "Weight (kg): ";
    int weight;
    if (not (in >> weight))
      return false;
    skip_line(in);

    std::cout << "Sex (M or F): ";
    char sex;
    if (not (in >> sex))
      return false;
    skip_line(in);
    sex = std::toupper(sex, std::locale());
    name_ = name;
    height_ = height;
    weight_ = weight;
    sex_ = sex;
    bmi_ = compute_bmi(height_, weight_);
    return true;
  }

  // adding const modifier to print
  void print(std::ostream& out, int threshold)
    const
  {
    out << std::setw(6) << height_
        << std::setw(7) << weight_
        << std::setw(3) << sex_
        << std::setw(6) << bmi_;
    if (bmi_ >= threshold)
      out << '*';
    else
      out << ' ';
    out << ' ' << name_ << '\n';
  }

  int height_;
  int weight_;
  int bmi_;   
  char sex_;  
  std::string name_;
};

void print_table(char sex, std::vector<record>& records, int threshold)
{
  std::cout << "Ht(cm) Wt(kg) Sex  BMI  Name\n";

  float bmi_sum(0);
  long int bmi_count(0);
  std::vector<int> tmpbmis;
  for (std::vector<record>::iterator iter(records.begin());
       iter != records.end();
       ++iter)
    {
      if (iter->sex_ == sex)
	{
	  bmi_sum = bmi_sum + iter->bmi_;
	  ++bmi_count;
	  tmpbmis.push_back(iter->bmi_);
	  iter->print(std::cout, threshold);
	}
    }

  if (bmi_count != 0)
    {
      std::cout << "Mean BMI = "
		<< std::setprecision(1) << std::fixed << bmi_sum / bmi_count
		<< '\n';

      std::sort(tmpbmis.begin(), tmpbmis.end());
      std::cout << "Median BMI = ";

      int i(tmpbmis.size() / 2);
      if (tmpbmis.size() % 2 == 0)
	std::cout << (tmpbmis.at(i) + tmpbmis.at(i-1)) / 2.0 << '\n';
      else
	std::cout << tmpbmis.at(i) << '\n';
    }
}

int main()
{
  std::locale::global(std::locale(""));
  std::cout.imbue(std::locale());
  std::cin.imbue(std::locale());

  std::vector<record> records;
  int threshold;

  std::cout << "Enter threshold BMI: ";
  if (not (std::cin >> threshold))
    return EXIT_FAILURE;
  skip_line(std::cin);

  std::cout << "Enter name, height (in cm), and weight (in kg) for each person:\n";
  record rec;
  while (rec.read(std::cin, records.size()+1))
    {
      records.push_back(rec);
      std::cout << "BMI = " << rec.bmi_ << '\n';
    }

  std::cout << "\n\nMale data\n";
  print_table('M', records, threshold);
  std::cout << "\nFemale data\n";
  print_table('F', records, threshold);
}
