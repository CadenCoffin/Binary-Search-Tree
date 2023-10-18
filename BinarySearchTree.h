/***************************************************************
Author:         Dr. Spiegel - Modified by Caden Coffin
Filename:       BinarySearchTree.h  
Purpose:        Header file for the Binary Tree ADT
***************************************************************/
#ifndef TREE_H
#define TREE_H
#include <iostream>
/*! 
    \class BinaryTree
    \brief Definition for the Binary Tree ADT
   
    Binary Tree can have terms added, removed, and printed based on user input
*/
 template <typename eltType> class BinaryTree;
/*! 
    \class TreeNode
    \brief A node found within the tree holding data that can be manipulated by the user.
   
    Data within the node can be added or removed and is able to be printed
*/
 template <typename eltType> class TreeNode {
 public: 
  TreeNode<eltType> *left, *right;
  eltType info;
 private:
  //eltType info;
  //TreeNode<eltType> *left,*right;  
  TreeNode(const eltType &data,
                        TreeNode<eltType> *lChild=NULL,TreeNode *rChild=NULL)
  {info=data;   left=lChild; right=rChild;  }
  
  friend class BinaryTree<eltType>;
 };

template <typename eltType> class BinaryTree {

public:

 // Constructor
 /*!
  *   \fn  BinaryTree<eltType>::BinaryTree ()
  *   \brief   Constructor for the Binary Tree ADT, sets the root of the Binary Tree to NULL
  *********************************************************************/
 BinaryTree();

 // Place Element into Tree
 // Returns 1 if inserted, 0 if Data already in tree
 /*!
  *   \fn  insertToTree (const eltType &data)
  *   \brief   Places an element into the Binary Tree 
  *   \param eltType & data, the data being the value stored within the tree                                                      
  *   \return 1 if the data in successfully inserted into the tree
  *   \return 0 if the data is already found within the tree
  *   Display Polynomial using Reverse InOrder Traversal, inserting + signs between terms
  *********************************************************************/
 int insertToTree(const eltType &data);

 // Search for Element in Tree
 // Assumes == is defined for eltType
 // Returns bool according to success
 /*!
  *   \fn  treeSearch (const eltType &key)
  *   \brief   Searches the Binary Tree for a requested element 
  *   \param eltType &key, the element that is being searched for within the Binary Tree                                                          
  *   \return t, if the element is found
  *   \return NULL, if the element is not found
  *********************************************************************/
 bool treeSearch(const eltType &data);

 // Retrieve Element from Tree (leaving Tree Intact)
 // Precondition: Item is in Tree
 /*!
  *   \fn  retrieveFromTree (const eltType &key)
  *   \brief   Retrieves a requested element from the tree while leaving the tree intact
  *   \param &key, the element aiming to be retrieved, item must already be within list                                                         
  *   \return t, pointer to the element
  *********************************************************************/
 eltType &retrieveFromTree(const eltType &data);

 // Remove an Element from the tree
 // Pre: Element is in the Tree
 /*!
  *   \fn  deleteFromTree(const eltType &data)
  *   \brief   Removes a selected element from the Binary Tree
  *   \param &data, the data within the Binary Tree that is being deleted/removed                                                            
  *   \return n/a
  *   Display Polynomial using Reverse InOrder Traversal, inserting + signs between terms
  *********************************************************************/
 void deleteFromTree(const eltType &data);

 // Display Tree using InOrder Traversal
  /*!
  *   \fn  inorder()
  *   \brief   Displays the Binary Tree using in order traversal                                                        
  *   \return n/a
  *   Display Polynomial using InOrder Traversal, inserting + signs between terms
  *********************************************************************/
 void inorder() const;

 // Display Tree using PreOrder Traversal
   /*!
  *   \fn  preorder()
  *   \brief   Displays the Binary Tree using pre order traversal                                                        
  *   \return n/a
  *   Display Polynomial using PreOrder Traversal, inserting + signs between terms
  *********************************************************************/
 void preorder() const;

 // Display Tree using PostOrder Traversal
   /*!
  *   \fn  postorder()
  *   \brief   Displays the Binary Tree using post order traversal                                                        
  *   \return n/a
  *   Display Polynomial using PostOrder Traversal, inserting + signs between terms
  *********************************************************************/
 void postorder() const;
 
 // Breadth first print
   /*!
  *   \fn  treePrint()
  *   \brief   Prints and displays the Binary Tree                                                     
  *   \return n/a
  *   Prints Polynomials using traversal, inserting + signs between terms
  *********************************************************************/
 void treePrint() const;
 
 protected:
 TreeNode<eltType> *root;
 
private:


 // Display Tree using InOrder Traversal
   /*!
  *   \fn  printInorder()
  *   \brief   Print the Binary Tree using in order traversal                                                        
  *   \return n/a
  *   Print Polynomial using InOrder Traversal, inserting + signs between terms
  *********************************************************************/
 void printInorder(TreeNode<eltType> *) const;

 // Display Tree using PreOrder Traversal
   /*!
  *   \fn  printPreorder()
  *   \brief   Print the Binary Tree using pre order traversal                                                        
  *   \return n/a
  *   Print Polynomial using PreOrder Traversal, inserting + signs between terms
  *********************************************************************/
 void printPreorder(TreeNode<eltType> *) const;

 // Display Tree using PostOrder Traversal
  /*!
  *   \fn  printPostorder()
  *   \brief   Print the Binary Tree using post order traversal                                                        
  *   \return n/a
  *   Print Polynomial using PostOrder Traversal, inserting + signs between terms
  *********************************************************************/
 void printPostorder(TreeNode<eltType> *) const;
 /*!
  *   \fn  treePrintHelper(TreeNode<eltType>)
  *   \brief   Helper function for printing of the binary tree  
  *   \param TreeNode<eltType>, element currently being printed
  *   \return n/a
  *   Help function for printing the binary tree through in order, and post and pre order printing
  *********************************************************************/
 void treePrintHelper(TreeNode<eltType> *) const;

};
