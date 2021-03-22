// Notes

//Trees are hierarchical data structures.
/* Trees DS : can be defined as a collection of entities called nodes linked together to simulate a hierarchy. 
It is a non-linear data structure. 
A null node/no child is the leaf node.

Terms : 
    -> N Nodes then N-1 edges in a valid tree.
    -> Depth of x = Length of path from root to x OR No. of edges in path from root to x.
    -> Height of x = No. of edges in logest path from x to a Leaf node.
    -> Height of tree = Height of the root Node(ie. No. of edges in logest path from root to a Leaf node).

Application:
    -> storing naturally hierarchical data ~ eg. file system
    -> Organise data for quick search, insertion, deletion ~ eg. Binary Search Tree
    -> Trie - Dictionary
    -> Network Routing Algorithm 

Complete Binary Tree - All levels except possibly the last are completely filled and all nodes are as left as possible.
-> Max no. of node at Level i = 2^i.

Perfect Binary Tree - All the levels are completely filled.
Height = Max depth
-> Max no. of nodes in a tree with height h = 2^0 + 2^1 + ... + 2^h
-> 2^(no. of levels) - 1  -> 2^(H+1)-1
-> Height = log(n+1) - 1 [heigh is equal to the log of n to tha base 2]
-> Searching/ insertion takes time proportional to the height of the tree

Balanced Binary Tree - The difference between height of left and right subtree for every node is not more than K (mostly 1).
-> Height - no. of the edges in the longest path from root to a leaf
-> Height of an empty tree = -1
-> Height of tree with 1 node = 0
-> diff = |Hleft - Hright| = 0 (for all nodes in a perfect tree)
-> if height is minimized then the cost of operations is also minimized

Implementing a Complete binary tree using arrays,
for Node at index i,
    left_child_index = 2i+1
    right_child_index = 2i+2
(True only for a complete binary tree)



*/
