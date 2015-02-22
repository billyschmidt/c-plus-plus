/**
 * Bill Schmidt
 * 4159697
 *
 * ordered_set class implementation
 *
 */

#include <vector>

#include "ordered_set.hpp"



/**********************************
 * CONSTRUCTOR
 **********************************/
ordered_set::ordered_set()
{
	root = 0;
	size = 0;
}



/**********************************
 * INSERT
 **********************************/
void ordered_set::insert(double x)
{
	if (root == 0)
		{
		// tree is empty, set root to point to a new node containing x
		root = new node(x, 0, 0);
		size++;
		}
	
	// tree is not empty -
	// so x either equals root key, (by req's this cannot happen)
	// or we need to go left, or go right
	
	else
		{
		node* curr(root);	  
		
		while (curr != 0)
			{
			
			// need to go left
			if (x < curr->val)
				{
				
				// if no left child, insert x here			
				if (curr->left == 0)
					{
					curr->left = new node(x, 0, 0);
					size++;
					break;
					}
				
				else
					{
					// set curr to left's child
					curr = curr->left;
					}
				}
			
			// going right (same as left)
			else
				{
				
				// if no right child is null, insert x here
				if (curr->right == 0)
					{
					curr->right = new node(x, 0, 0);
					size++;
					break;
					}
				
				else
					{
					// set curr to right child
					curr = curr->right;					
					}
				}
			} //while
		} //else
}



/**********************************
 * TREE WALK
 **********************************/
void ordered_set::inorder_tree_walk(std::vector<double>* v, node* n)
{
	if (n != 0)
		{
		inorder_tree_walk(v, n->left);
		
		v->push_back(n->val);
		
		inorder_tree_walk(v, n->right);
		}
}



/**********************************
 * SORT
 **********************************/
std::vector<double>* ordered_set::sort()
{
	std::vector<double>* vec_doubles = new std::vector<double>;
	
	inorder_tree_walk(vec_doubles, root);
	
	return vec_doubles;
}

