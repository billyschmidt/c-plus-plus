#include <algorithm>
#include <iomanip>
#include <iostream>
#include <istream>
#include <limits>
#include <ostream>
#include <string>
#include <vector>

// take height and weight, calculate BMI, return int
int get_bmi(int height, int weight)
{
  return (weight * 10000 / (height * height));
}

void skip_line()
{
  std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

// bool to get records from prompt with all vecotrs as params
bool get_record(std::vector<std::string>& persons, std::vector<int>& weights, std::vector<int>& heights, std::vector<char>& genders)
{  
  int height(0);
  std::string person;  
  char gender(' ');
  int weight(0);
  
  std::cout << "Person " << persons.size()+1 << " name:";
  std::getline(std::cin, person);
  
  std::cout << "Height (cm): ";
  std::cin >> height;
  skip_line();
  
  std::cout << "Weight (kg): ";
  std::cin >> weight;
  skip_line();
  
  std::cout << "Gender (M or F): ";
  std::cin >> gender;
  skip_line();

  // put info into vectors using push_back  
  persons.push_back(person);
  heights.push_back(height);
  weights.push_back(weight);
  genders.push_back(gender);

  return true;
}

// display chart
void display_chart(char gender, std::vector<int>& heights, std::vector<int>& weights, std::vector<char>& genders, std::vector<std::string>& persons, std::vector<int>& bmis, int threshold)
{
  float bmi_sum(0);
  long int bmi_count(0);
  std::vector<int> temp;

  // print table header
  std::cout << "Height(cm) Weight(kg) Gender  BMI  person\n";

  // keep track of people entered
  for (std::vector<int>::size_type i(0); i != weights.size(); ++i)
    if (genders.at(i) == gender)
      {
	bmi_sum += bmis.at(i);
	bmi_count++;
	temp.push_back(bmis.at(i));
	
	// setup proper formatting
	std::cout << std::setw(8) << heights.at(i)
		  << std::setw(8) << weights.at(i)
		  << std::setw(4) << genders.at(i)
		  << std::setw(6) << bmis.at(i);
		      
	// output asterik next to bmis greater than threshold
	if (bmis.at(i) >= threshold)
	  std::cout << '*';
	else
	  std::cout << ' ' << persons.at(i) << '\n';
      }

  // computing the mean
  std::cout << "Mean BMI = " << std::setprecision(2) << std::fixed << bmi_sum / bmi_count << '\n';
  std::sort(temp.begin(), temp.end());
  
  // computing the median
  std::cout << "Median BMI = ";
  int i(temp.size() / 2);
  if (temp.size() % 2 == 0)
    std::cout << (temp.at(i) + temp.at(i-1)) / 2.0 << '\n';
  else
    std::cout << temp.at(i) << '\n';
}

/////////////
//// MAIN ////
/////////////
int main()
{
  // create vectors and threshold var  
  std::vector<std::string> persons;
  std::vector<int> heights;
  std::vector<int> weights;
  std::vector<char> genders;
  std::vector<int> bmis;
  int threshold;

  // start getting user data
  std::cout << "Please enter the threshold BMI: ";
  std::cin >> threshold;
  skip_line();

  // keep getting user data until EOF keystroke
  std::cout << "Please enter the following information for each person:\n"; 
  while (get_record(persons, heights, weights, genders))
    {
      int bmi(get_bmi(heights.back(), weights.back()));
      bmis.push_back(bmi);
      std::cout << "BMI = " << bmi << '\n';
    }

  // print male info
  std::cout << "\n\nMale BMI information:\n";
  display_chart('M', heights, weights, genders, persons, bmis, threshold);

  // print femaile info
  std::cout << "\nfemale BMI information:\n";
  display_chart('F', heights, weights, genders, persons, bmis, threshold);
}
