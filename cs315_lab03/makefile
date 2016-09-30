CFLAGS= -ggdb -std=c++11

# the first target ("all") is made by default.
# So, we list all targets that need to be made here.
all: binTree.x

# dependencies for isSorted
binTree.x: main.o TreeNode.o BinSearchTree.o
	g++ $(CFLAGS) -o binTree.x main.o TreeNode.o BinSearchTree.o

main.o: main.cpp BinSearchTree.hpp TreeNode.hpp
	g++ $(CFLAGS) -c -o main.o main.cpp

TreeNode.o: TreeNode.hpp TreeNode.cpp
	g++ $(CFLAGS) -c -o TreeNode.o TreeNode.cpp

BinSearchTree.o:  BinSearchTree.hpp BinSearchTree.cpp
	g++ $(CFLAGS) -c -o BinSearchTree.o BinSearchTree.cpp

# At the shell prompt, type: 
# make clean
# to remove the .o, .x and Emacs backup files.

clean:
	rm -f *.o *.x *~