/**
 * rewriting high-card program to use a list
 *
 */

#include <iostream>
#include <list>
#include <ostream>

#include "card.hpp"
#include "randomint.hpp"

int main()
{
  using namespace std;

  list<card> deck(52);
  generate(deck.begin(), deck.end(), card_generator());

  for (int i(0); i != 10; ++i) {

    randomint selection(0, deck.size() - 1);

    list<card>::iterator computer_pick(deck.begin());

    advance(computer_pick, selection());

    cout << "I selected: " << *computer_pick << '\n';

    list<card>::iterator user_pick(deck.begin());

    advance(user_pick, selection());

    cout << "You selected: " << *user_pick << '\n';

    if (acehigh_compare(*computer_pick, *user_pick)) {
      cout << "You win!\n";
    }
      
    else {
      cout << "I win!\n";
    }
      
    deck.erase(computer_pick);
    deck.erase(user_pick);
  }
}
