#include "my_mat.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_PRODUCTS 5  // Number of products   
#define MAX_CAPACITY 20 // Max capacity of bag

#define MAX(x, y) ((x) > (y) ? (x) : (y)) /// Return the maximum

int chooseItems(int weights[], int values[], int selected_bool[]);

int main() {
    int selected_bool[NUM_PRODUCTS] = {0};
    char products[NUM_PRODUCTS];
    int values[NUM_PRODUCTS] = {0};
    int weights[NUM_PRODUCTS] = {0};

    for (int i = 0; i < NUM_PRODUCTS; i++) {
         scanf(" %c %d %d", &products[i], &values[i], &weights[i]);
    }
    int maxProfit = chooseItems(weights, values, selected_bool);

    printf("Maximum profit: %d\n", maxProfit);
    printf("Selected items:");

    for (int i = 0; i < NUM_PRODUCTS; i++) {
        if (selected_bool[i] == 1)
            printf(" %c", products[i]);
    }

    int result[NUM_PRODUCTS]; // Define result array
    for (int i = 0; i < NUM_PRODUCTS; ++i) {
        result[i] = selected_bool[i];
    }

    return 0;
}


int chooseItems(int weights[], int values[], int selected_bool[]) {
   
    int matrix[NUM_PRODUCTS + 1][MAX_CAPACITY + 1];
    for (int i = 0; i <= NUM_PRODUCTS; i++) {
        for (int j = 0; j <= MAX_CAPACITY; j++) {         // Fill the matrix by using dynamic programming
            if (i == 0 || j == 0)
                matrix[i][j] = 0;
            else if (weights[i - 1] <= j)
                matrix[i][j] = MAX(matrix[i - 1][j], values[i - 1] + matrix[i - 1][j - weights[i - 1]]);
            else
                matrix[i][j] = matrix[i - 1][j];
        }
    }
    int all_weight = MAX_CAPACITY;
        for (size_t i = NUM_PRODUCTS; i > 0; i--) {            // Find the items that we take
            if (matrix[i][all_weight] != matrix[i - 1][all_weight]) {
                selected_bool[i - 1] = TRUE;
                all_weight -= weights[i - 1];        
            }
        }
    return matrix[NUM_PRODUCTS][MAX_CAPACITY];
}

