
std::vector<int> add(std::vector<int> v, int a)
{
  std::vector<int> result;
  for (std::vecotr<int>::iterator i(v.begin()); i != v.end(); ++i)
    result.push_back(*i+a);
  return result;
}

// func call
input= add(input, 13);


