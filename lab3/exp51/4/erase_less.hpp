/**
 * erasing elements from a sequence container
 *
 */

template<class Container>
void erase_less(Container& cont)
{
  typename Container::iterator prev(cont.end());
  typename Container::iterator iter(cont.begin());

  while (iter != cont.end()) {
    
    if (prev != cont.end() and not (*prev < *iter)) {
      iter = cont.erase(iter);
    }
    
    else {
      prev = iter;
      ++iter;
    }
  }
}
