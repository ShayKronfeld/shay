#include "my_mat.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_PRODUCTS 5  // Number of products   
#define MAX_CAPACITY 20 // Max capacity of bag

/* Return the maximum of two values */
#define MAX(x, y) ((x) > (y) ? (x) : (y))

/* This function creates the table and enters selected_bool the selected items and returns the max value of all the products */
int chooseItems(int weights[], int values[], int selected_bool[]) {
    /* Create the table */
    int matrix[NUM_PRODUCTS + 1][MAX_CAPACITY + 1];
    for (int i = 0; i <= NUM_PRODUCTS; i++) {
        for (int j = 0; j <= MAX_CAPACITY; j++) {
            if (i == 0 || j == 0)
                matrix[i][j] = 0;
            else if (weights[i - 1] <= j)
                matrix[i][j] = MAX(matrix[i - 1][j], values[i - 1] + matrix[i - 1][j - weights[i - 1]]);
            else
                matrix[i][j] = matrix[i - 1][j];
        }
    }
    int total_weight = MAX_CAPACITY;
        for (size_t i = NUM_PRODUCTS; i > 0; i--) {
            if (matrix[i][total_weight] != matrix[i - 1][total_weight]) {
                selected_bool[i - 1] = TRUE;
                total_weight -= weights[i - 1];        
            }
        }
    return matrix[NUM_PRODUCTS][MAX_CAPACITY];
}

int main() {
    int selected_bool[NUM_PRODUCTS];
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



// #include <stdio.h>

// #define MAX_WEIGHT 20           // Maximum weight
// #define NUM_ITEMS 5             // Number of items
// #define MAX_STRING_LENGTH 20    // Max length for a name of the item
// #define TRUE 1
// #define FALSE 0

// int knapSack(int weights[MAX_WEIGHT], int values[NUM_ITEMS], int selected[NUM_ITEMS]);

// int main() {
//     char item_names[NUM_ITEMS][NUM_ITEMS+1];          
//     int item_values[NUM_ITEMS] = {0};
//     int item_weights[MAX_WEIGHT] = {0};

//     for (size_t i = 0; i < NUM_ITEMS; i++) {
//         scanf("%s %d %d", item_names[i], &item_values[i], &item_weights[i]);   // scan the values for the items
//         if (i < NUM_ITEMS - 1) {
//             scanf(" ");
//         }
//     }

//     int result[NUM_ITEMS] = {FALSE}; 

//     int max_profit = knapSack(item_weights, item_values, result);

//     printf("Maximum profit: %d\n", max_profit);
//     printf("Selected items:");

//     for (size_t i = 0; i < NUM_ITEMS; i++) {
//         if (result[i] == TRUE) {                    //this item in the bag
//             printf(" %s", item_names[i]);
//         }
//     }

//     return 0;
// }

// int knapSack(int weights[MAX_WEIGHT], int values[NUM_ITEMS], int selected[NUM_ITEMS]) {
//     int matrix[NUM_ITEMS + 1][MAX_WEIGHT + 1];      // one more its for line zero

//     for (size_t i = 0; i <= NUM_ITEMS; i++) {       // Initialize the matrix with 0
//         for (size_t j = 0; j <= MAX_WEIGHT; j++) {
//             matrix[i][j] = 0;
//         }
//     }

//     for (size_t i = 1; i <= NUM_ITEMS; i++) {       // make the dynamic programming
//         for (size_t j = 1; j <= MAX_WEIGHT; j++) {
//             if (weights[i - 1] <= j) {
//                 if (values[i - 1] + matrix[i - 1][j - weights[i - 1]] > matrix[i - 1][j]) {
//                     matrix[i][j] = values[i - 1] + matrix[i - 1][j - weights[i - 1]];
//                 } 
//                 else {
//                     matrix[i][j] = matrix[i - 1][j];
//                 }
//             } 
//             else {
//                 matrix[i][j] = matrix[i - 1][j];
//             }
//         }
//     }

//     // int total_weight = MAX_WEIGHT;
//     // for (size_t i = NUM_ITEMS; i > 0; i--) {
//     //     if (matrix[i][total_weight] != matrix[i - 1][total_weight]) {
//     //         selected[i - 1] = TRUE;
//     //         total_weight -= weights[i - 1];        
//     //     }
//     // }

//     int maxV= checkSelectedBool(weights, values, selected_bool);
    
//     return matrix[NUM_ITEMS][MAX_WEIGHT];
// }

// int checkSelectedBool(int weights[], int values[], int selected_bool[]){  //in the loop move on all the items and  check if is selected bool 
//    int maxV = 0;
//     for (int i = 0; i < MAX_WEIGHT; i++)
//     {
//         if (selected_bool[i]= TRUE)
//         {
//             maxV = maxV + values[i];
//         }
//     }
//     return maxV;
// }