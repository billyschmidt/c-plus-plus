/**
 * Bill Schmidt
 * 4159697
 *
 * ordered_set class declaration
 *
 */

#include <vector>

class ordered_set
{
	private:
	
	class node
	{
		public:
		double val;
		node* left;
		node* right;
		
		node(double v, node* l, node* r) : val(v), left(l), right(r) {}
	};
		
	node* root;	
	int size;
	
	public:  
	
	ordered_set();

	void insert(double x);
	
	std::vector<double>* sort();
	
	void inorder_tree_walk(std::vector<double>* v, node* n);

};
