#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
    int index; // To maintain original upper-triangular order for equal weights
};

// Structure to represent a Disjoint Set (Union-Find)
struct Subset {
    int parent;
    int rank;
};

// Helper function to find the root of a set using path compression
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent); // Path compression
    }
    return subsets[i].parent;
}

// Helper function to unite two sets using union by rank
void unionSet(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
}