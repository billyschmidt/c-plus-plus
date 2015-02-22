// Bill Schmidt 4159697
// different styles of string output

#include <iostream>
#include <ostream>

int main()
{
   std::cout << "Shape\tSides\n" << "-----\t-----\n";
   std::cout << "Square\t" << 4 << '\n' <<
                "Circle\t?\n";
}
