/***************************************************************
Author:         Dr. Spiegel - Modified by Caden Coffin
Filename:       TermTree.h  
Purpose:        Header file for the Term Tree Reverse Print
***************************************************************/
#ifndef TERMTREE_H
#define TERMTREE_H

#include "BinarySearchTree.h"
#include "Term.h"

using namespace std;

const char symbol='+';
/*!
  *   \class  TermTree
  *   \brief   A binary tree of terms added by user input stored in descending order from the root
  *********************************************************************/
class TermTree : public BinaryTree<Term> {
//               ^^^^^^
public:

 TermTree(); 

/*!
  *   \fn  printRevOrder
  *   \brief   Helper function to print preorder with only symbol parameter
  *                                                                   
  *  , Display Polynomial using Reverse InOrder Traversal  
  *********************************************************************/
 void printRevOrder() const;

private:
/*!
  *   \fn  printReverseInorder
  *   \brief   Prints the polynomial inorder reversed using recursion 
  *   \param TreeNode<eltType> *t (import) - a pointer to the tree to be printed
  *   \param bool& first (import/export) - if the current node is the first one 
  *		to be printed, it's true --> no + sign. Otherwise, false --> + sign first                                                            
  *   \return n/a
  *   Display Polynomial using Reverse InOrder Traversal, inserting + signs between terms
  *********************************************************************/
  void printReverseInorder(TreeNode<Term> *t, bool& first) const;

};

#endif
