cc=g++
debugFlag=-g

tree: BinarySearchTree.o Treetest.o Term.o TermTree.o
	$(cc) -o tree Treetest.o BinarySearchTree.o Term.o TermTree.o $(debugFlag)

Treetest.o: Treetest.cpp  BinarySearchTree.h
	$(cc) -c Treetest.cpp $(debugFlag)

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h 
	$(cc) -c BinarySearchTree.cpp $(debugFlag)

Term.o: Term.cpp Term.h 
	$(cc) -c Term.cpp $(debugFlag)
	
TermTree.o: TermTree.cpp TermTree.h Term.h
	$(cc) -c TermTree.cpp $(debugFlag)

clean: 
	\rm -f *.o tree    
