/***************************************************************
Author:         Dr. Spiegel - Modified by Caden Coffin
Filename:       TermTree.cpp
Purpose:        
***************************************************************/
#include "TermTree.h"

// This is Complete
TermTree::TermTree() : BinaryTree()
{}

// Need Helper to Recursively Print the Polynomial
//The boolean is a reference so once the first node is printed, the rest have their flag changed
/*!
  *   \fn  printReverseInorder
  *   \brief   Prints the polynomial inorder reversed using recursion 
  *   \param TreeNode<eltType> *t (import) - a pointer to the tree to be printed
  *   \param bool& first (import/export) - if the current node is the first one 
  *		to be printed, it's true --> no + sign. Otherwise, false --> + sign first                                                            
  *   \return n/a
  *   Display Polynomial using Reverse InOrder Traversal, inserting + signs between terms
  *********************************************************************/
void TermTree::printReverseInorder(TreeNode<Term> *t, bool& first) const
{ if (t) {

// Complete the function body
printReverseInorder(t->right, first);
if(first == true)
{
	cout << t -> info;
	first = false;
}
else 
{
	cout << "+" << t -> info;
}
printReverseInorder (t->left,first);
}
}

// Display Polynomial using Reverse InOrder Traversal
/*!
  *   \fn  printRevOrder
  *   \brief   Helper function to print preorder with only symbol parameter
  *                                                                   
  *  , Display Polynomial using Reverse InOrder Traversal  
  *********************************************************************/
void TermTree::printRevOrder() const
{ bool firstNode = true;
  printReverseInorder(root, firstNode);
  cout << endl;
}

