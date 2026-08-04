#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20
#define MAX_SUBSETS 100000

int n, target_sum;
int set[MAX_N];

// Storage for found subsets
int results[MAX_SUBSETS][MAX_N];
int result_sizes[MAX_SUBSETS];
int total_subsets = 0;

// Current subset path during backtracking
int current_subset[MAX_N];
int current_size = 0;

void findSubsets(int index, int current_sum) {
    if (current_sum == target_sum) {
        for (int i = 0; i < current_size; i++) {
            results[total_subsets][i] = current_subset[i];
        }
        result_sizes[total_subsets] = current_size;
        total_subsets++;
        return;
    }

    if (index >= n || current_sum > target_sum) {
        return;
    }

    // Include element
    current_subset[current_size] = set[index];
    current_size++;
    findSubsets(index + 1, current_sum + set[index]);
}