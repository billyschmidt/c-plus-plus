/*
 * Bill Schmidt
 * 4159697
 * applying experience with vector to write high card program 
 *
 */

#include <deque>
#include <iostream>
#include <ostream>

#include "card.hpp"
#include "randomint.hpp"

int main()
{
  std::deque<card> deck(52);

  std::generate(deck.begin(), deck.end(), card_generator());
  
  for (int i(0); i != 10; ++i) {

    randomint selection(0, deck.size() - 1);
      
    card computer_card(deck.at(selection()));
    std::cout << "My selection: " << computer_card << '\n';
      
    card user_card(deck.at(selection()));
    std::cout << "Your selection: " << user_card << '\n';
      
    if (acehigh_compare(computer_card, user_card)) {
      std::cout << "You win!\n";
    }
      
    else {
      std::cout << "I win!\n";
    }
      
    std::deque<card>::iterator end(std::remove(deck.begin(), deck.end(), computer_card));

    end = std::remove(deck.begin(), end, user_card);

    deck.erase(end, deck.end());
  }
}
