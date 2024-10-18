# Problem Description
The problem you are trying to solve involves finding the shortest distance from a given node s to all other nodes in a unweighted undirected graph. This can be achieved by using an adjacency matrix to represent the graph and boolean matrix multiplication. The adjacency matrix is a square matrix where the rows and columns represent the nodes in the graph, and the entries represent the edges between the nodes. The value of an entry is 1 if there is an edge between the corresponding nodes, and 0 otherwise. To find the shortest distance from node s to all other nodes, you can use matrix multiplication to calculate the powers of the adjacency matrix. The entries of i-th power of the adjacency matrix represents whether the corresponding node pair has a path of length i between them or not. Look at the matrix class description for knowing about matrix class.

PLEASE READ
The input and output handling HAVE BEEN DONE FOR YOU in main.cpp.
All you need to do is complete function bfs(...)

# Input format
Graph is represented as an edgelist, where each edge is represented as a pair of integers (u, v) denoting an edge from node u to node v. The variable n represents the number of nodes in the graph. **Assume that the nodes are numbered from 0 to n-1** and s represents the source node from which the shortest distance to all other nodes is to be calculated. The variable a is an integer array that stores the shortest distance from the source node s to all other nodes in the graph.

# Output format
You have to fill the array a. `a[i]` should represent distace of node i from s. If you can't reach any node i from source node s through any path then `a[i]` should be -1.
For example: `a[s] = 0` for any graph. 

# Hint for Algorithm
1. Create a boolean Matrix m representing the adjacency matrix by default all entries are set to false
2. Iterate over the edgelist and make the entries corresponding to edges as true in the adjacency matrix
3. Intialize the array a with all entries with all entries as -1
4. Fill a[s]
5. Now iteratively calculate m' = m^{i} for i in 1 to n-1, and then the first time when m'[s][j]
    becomes true mark a[j] by the corresponding i.

# Matrix Class

Matrix.cpp defines a Matrix class that represents a boolean matrix. The class has a constructor that takes an integer n as input and initializes a square matrix of size n with all values set to false. The class also has a Multiply function that takes two matrices m2 and m3 as input and returns their boolean product as a new matrix m4. The getN function returns the size of the matrix. The set function sets the value of a particular element in the matrix. The set_false function sets all elements in the matrix to false. The get_value function returns the value of a particular element in the matrix.


// Example for constructor
`Matrix m(3);` // creates a 3x3 matrix with all values set to false

// Example for set function
`m.set(0, 1, true);` // sets the value of element (0, 1) to true

// Example for set_false function
`m.set_false();` // sets all elements in the matrix to false

// Example for get_value function
`bool val = m.get_value(0, 1);` // gets the value of element (0, 1)

// Example for getN function
`int size = m.getN();` // gets the size of the matrix

// Example for Multiply function
`Matrix m2(3);`
`m2.set(0, 1, true);`
`Matrix m3(3);`
`m3.set(1, 0, true);`
`Matrix m4 = m.Multiply(m2, m3);` // multiplies m2 and m3 and returns the result as a new matrix m4


