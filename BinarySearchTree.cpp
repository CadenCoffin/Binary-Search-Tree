/***************************************************************
Author:         Dr. Spiegel - Modified by Caden Coffin
Filename:       BinarySearchTree.cpp   
Purpose:        A Binary Tree ADT implemented with TreeNode linked structures. 
				The Tree is able to have terms added and removed that can then be printed 
				either in descending order or as a tree from the root.
***************************************************************/
#include <iostream>
#include <string>
#include <queue>
#include "BinarySearchTree.h"

using namespace std;

// Constructor
/*!
  *   \fn  BinaryTree<eltType>::BinaryTree ()
  *   \brief   Constructor for the Binary Tree ADT, sets the root of the Binary Tree to NULL
  *********************************************************************/
template <typename eltType> BinaryTree<eltType>::BinaryTree()
{root=NULL;}

// Place Element into Tree
// Returns 1 if inserted, 0 if data already in tree
/*!
  *   \fn  insertToTree (const eltType &data)
  *   \brief   Places an element into the Binary Tree 
  *   \param eltType & data, the data being the value stored within the tree                                                      
  *   \return 1 if the data in successfully inserted into the tree
  *   \return 0 if the data is already found within the tree
  *   Display Polynomial using Reverse InOrder Traversal, inserting + signs between terms
  *********************************************************************/
template <typename eltType>
	  int BinaryTree<eltType>::insertToTree(const eltType &data)
{if (root==NULL) { // Empty Tree
  root=new TreeNode<eltType>(data);
  return(1);
 }
 // Search for spot to put data; We only stop when we get to the bottom (NULL)
 TreeNode<eltType> *t=root,*parent;
 while(t!=NULL) {
   if (t->info==data){ // data already in Tree
     t -> info += data;
     return(0); 
   }
   parent=t; // Set the trail pointer to the ancestor of where we're going
   if (data<t->info) 
     t=t->left;
   else 
     t=t->right;
 }
 // Found the spot; insert node.
 if (data<parent->info) parent->left=new TreeNode<eltType>(data);
 else parent->right=new TreeNode<eltType>(data);
 return(1);
}

// Search for Element in Tree
// Assumes == is defined for eltType
// Returns Ptr to Elt if Found, NULL otherwise
/*!
  *   \fn  treeSearch (const eltType &key)
  *   \brief   Searches the Binary Tree for a requested element 
  *   \param eltType &key, the element that is being searched for within the Binary Tree                                                          
  *   \return t, if the element is found
  *   \return NULL, if the element is not found
  *********************************************************************/
template <typename eltType>
	bool BinaryTree<eltType>::treeSearch(const eltType &key)
{TreeNode<eltType> *t=root;
 while (t && t->info != key)
   if (key < t->info) 
     t=t->left;
   else 
     t=t->right;
 return(t);	// auto convert int to bool
}

// Retrieve Element from Tree (leaving Tree Intact)
// Precondition: Item is in Tree
/*!
  *   \fn  retrieveFromTree (const eltType &key)
  *   \brief   Retrieves a requested element from the tree while leaving the tree intact
  *   \param &key, the element aiming to be retrieved, item must already be within list                                                         
  *   \return t, pointer to the element
  *********************************************************************/
template <typename eltType>
   eltType &BinaryTree<eltType>::retrieveFromTree(const eltType &key) 
{TreeNode<eltType> *t;
 for (t=root;t->info!=key;)
  if (key<t->info) t=t->left;
  else t=t->right;
 return(t->info);
}

// Remove an Element from the tree
// Precondition: Element is in the Tree; 
/*!
  *   \fn  deleteFromTree(const eltType &data)
  *   \brief   Removes a selected element from the Binary Tree
  *   \param &data, the data within the Binary Tree that is being deleted/removed                                                            
  *   \return n/a
  *   Display Polynomial using Reverse InOrder Traversal, inserting + signs between terms
  *********************************************************************/
template <typename eltType>
      void BinaryTree<eltType>::deleteFromTree(const eltType &data)
{TreeNode<eltType> *nodeWithData,*nodeToDelete,*t=root,*trailT=NULL;
 // Find spot
 while (t->info!=data) {  // safe because of precondition
  trailT=t;
  if (data<t->info) t=t->left;
  else t=t->right;
 }
 nodeWithData=t;  // Hold onto the data Node for later deletion
 // Case 1: Leaf?
 if (!(nodeWithData->left) && !(nodeWithData->right)) {
  // No Subtrees, node is leaf...Wipe it
  // Is it the root?
  if (nodeWithData==root)
    root=NULL;
  else if (trailT->right==nodeWithData) // Parent's right child
    trailT->right=NULL;
  else 
    trailT->left=NULL;
  nodeToDelete=nodeWithData;    // free this at the end
 }
 else if (!(nodeWithData->left)) {  
  // If 1st condition false and this one's true, there's a right subtree
  if (!trailT) { // Node to delete is root and there is no left subtree
    nodeToDelete=root;
    root=root->right;
  }
  else { // Point parent's pointer to this node to this node's right child
    if (trailT->right==nodeWithData) 
      trailT->right=nodeWithData->right;
    else 
      trailT->left=nodeWithData->right;
    nodeToDelete=nodeWithData;
  }
 }
 else if (!(nodeWithData->right)) {  
   // If 1st 2 conditions false and this one's true, there's a left subtree
   if (!trailT) { // Node to delete is root and there is no left subtree
     nodeToDelete=root;
     root=root->left;
   }
   else {// Otherwise, move up the right subtree
     if (trailT->right==nodeWithData) 
        trailT->right=nodeWithData->left;
     else 
        trailT->left=nodeWithData->left;
     nodeToDelete=nodeWithData;
   }
 } 
 else { // If you make it here, node has two children
   // Go to rightmost node in left subtree; we know there's a right child...
  for (trailT=nodeWithData,t=nodeWithData->left;
                                        t->right!=NULL;trailT=t,t=t->right);
  // Want to copy data from node with 0 or 1 child to node with data to delete 
  // Place node data in NodeWithData
  nodeWithData->info=t->info;
   // Set the parent of source node to point at source node's left child 
   //   (We know it hasn't a right child. Also ok if no left child.)
  if (trailT==nodeWithData) 
    // Need to point parent correctly. 
    //   See if after the we went left there was no right child
    //   If there was no right child, this is rightmost node in left subtree
    trailT->left=t->left;
  else // we did go right; after going left, there was a right child
   // rightmost node has no r. child, so point its parent at its l. child 
   trailT->right=t->left;
  nodeToDelete=t;
 }
 delete nodeToDelete;
}

// Need Helper to Recursively Print the Tree
template <typename eltType>
     void BinaryTree<eltType>::printInorder(TreeNode<eltType> *t) const
//void printTheTree(TreeNode *T)
 /*!
  *   \fn  printInorder()
  *   \brief   Print the Binary Tree using in order traversal                                                        
  *   \return n/a
  *   Print Polynomial using InOrder Traversal, inserting + signs between terms
  *********************************************************************/
{if (t) {
  printInorder(t->left);
  cout << t->info << "+";
  printInorder(t->right);
 }
}

// Display Tree using InOrder Traversal
/*!
  *   \fn  inorder()
  *   \brief   Displays the Binary Tree using in order traversal                                                        
  *   \return n/a
  *   Display Polynomial using InOrder Traversal, inserting + signs between terms
  *********************************************************************/
template <typename eltType> void BinaryTree<eltType>::inorder() const
{printInorder(root);}

// Need Helper to Recursively Print the Tree
/*!
  *   \fn  printPreorder()
  *   \brief   Print the Binary Tree using pre order traversal                                                        
  *   \return n/a
  *   Print Polynomial using PreOrder Traversal, inserting + signs between terms
  *********************************************************************/
template <typename eltType>
   void BinaryTree<eltType>::printPreorder(TreeNode<eltType> *t) const
//void printTheTree(TreeNode *t)
{if (t) {
  cout << t->info << endl;
  printPreorder(t->left);
  printPreorder(t->right);
 }
}

// Display Tree using InOrder Traversal
/*!
  *   \fn  preorder()
  *   \brief   Displays the Binary Tree using pre order traversal                                                        
  *   \return n/a
  *   Display Polynomial using PreOrder Traversal, inserting + signs between terms
  *********************************************************************/
template <typename eltType> void BinaryTree<eltType>::preorder() const
{printInorder(root);}

// Need Helper to Recursively Print the Tree

template <typename eltType>
  void BinaryTree<eltType>::printPostorder(TreeNode<eltType> *t) const
//void printTheTree(TreeNode *t)
/*!
  *   \fn  printPostorder()
  *   \brief   Print the Binary Tree using post order traversal                                                        
  *   \return n/a
  *   Print Polynomial using PostOrder Traversal, inserting + signs between terms
  *********************************************************************/
{if (t) {
  printPostorder(t->left);
  printPostorder(t->right);
  cout << t->info << endl;
 }
}

// Display Tree using InOrder Traversal
/*!
  *   \fn  treePrint()
  *   \brief   Prints and displays the Binary Tree                                                     
  *   \return n/a
  *   Prints Polynomials using traversal, inserting + signs between terms
  *********************************************************************/
template <typename eltType> void BinaryTree<eltType>::postorder() const
{printInorder(root);}
/*!
  *   \fn  treePrint()
  *   \brief   Prints and displays the Binary Tree                                                     
  *   \return n/a
  *   Prints Polynomials using traversal, inserting + signs between terms
  *********************************************************************/
template <typename eltType> void BinaryTree<eltType>::treePrint() const
{treePrintHelper(root);}

template <typename eltType> void BinaryTree<eltType>::
                        treePrintHelper(TreeNode<eltType> *root) const
{queue<TreeNode<eltType> *> Q;
 // A dummy node to mark end of level
 TreeNode<eltType> *dummy=new  TreeNode<eltType>(-1);
 if (root) {
   cout << root->info << " " << endl;
   Q.push(root->left);
   Q.push(root->right);
   Q.push(dummy);
 }
 TreeNode<eltType> *t=root;
 while (!Q.empty()) {
  t=Q.front();
  Q.pop();
  if (t==dummy) {
   if (!Q.empty()) 
    Q.push(dummy);
   cout << endl;
  }
  else if (t) {
   cout << t->info << " ";
   Q.push(t->left);
   Q.push(t->right);
  } 
 }
}

#include "Term.h"

template class BinaryTree<Term>
