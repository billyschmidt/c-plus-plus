
/* 
   quick and dirty implementation of the necessary content of card.hpp, listing 51-5
   ---put this filename on the command line along with whichever C++ file uses card.cpp when compiling

   see the note on the 1902 forum 

*/

#include <istream>
#include <ostream>

#include "card.hpp"

void card::assign(rank r, suit s) { 
  rank_ = r; suit_ = s;
}

bool operator==(card a, card b) {
  return a.get_suit() == b.get_suit() and a.get_rank() == b.get_rank();
}

bool operator!=(card a, card b) {
  return not ( a == b );
}

//does no error checking
std::ostream& operator<<(std::ostream& out, card c) {
  int suit(c.get_suit());
  int rank(c.get_rank());
  switch( rank ) {
  case card::ace: out << "A"; break;
  case card::king: out << "K"; break;
  case card::queen: out << "Q"; break;
  case card::jack: out << "J"; break;
  default: out << rank; break;
  }
  switch( suit ) {
  case card::hearts : out << "H"; break;
  case card::clubs : out << "C"; break;
  case card::diamonds : out << "D"; break;
  case card::spades : out << "S"; break;
  }
  return out;
}

//does no error checking; untested
std::istream& operator>>(std::istream& in, card& c) {
  std::string token;
  in >> token;
  int rank, suit;
  if( token.length() == 3 ) {
    rank = 10;
    switch( token[2] ) {
    case 'H' : suit = card::hearts; break;
    case 'C' : suit = card::clubs; break;
    case 'D' : suit = card::diamonds; break;
    case 'S' : suit = card::spades; break;
    }
  } else {
    switch( token[0] ) {
    case 'A': rank = card::ace; break;
    case 'K': rank = card::king; break;
    case 'Q': rank = card::queen; break;
    case 'J': rank = card::jack; break;
    }
  }
  c = card(rank, suit);
  return in;
}

bool acehigh_compare(card a, card b) {
  return a.get_rank() < b.get_rank(); //true if b outranks (arbitrary definition)
}

bool acelow_compare(card a, card b) { //untested
  bool a_ace( a.get_rank() == card::ace );
  bool b_ace( b.get_rank() == card::ace );
  if( not (a_ace and b_ace)  ) return acehigh_compare(a, b);
  return !b_ace; //if we get to this line, then b can only outrank a if not an ace
}

card_generator::card_generator() : card_(2, card::diamonds) { /* empty */ }

card card_generator::operator()() {
  card c(card_);
  int rank( c.get_rank() ), suit( c.get_suit() );
  if( rank < card::ace ) {
    ++rank;
  } else {
    rank = 2;
    if( suit < card::spades ) {
      ++suit;
    } else {
      suit = card::diamonds;
    }
  }
  card_ = card(rank, suit);
  return c;
}


