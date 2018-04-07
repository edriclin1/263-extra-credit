#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int value (int num_items, int weight_limit, int (&knapsack_values)[7][46], int (&item_weights)[7], int (&item_values)[7]);

int main (int argc, char** argv) {
	
	// max items to choose
	int max_items = 6;

	// max weight 
	int max_weight = 45;

	// possible weights for each item (start list at index 1)
	int item_weights[] = {0, 15, 25, 45, 30, 23, 37};

	// possible values for each item (start list at index 1)
	int item_values[] = {0, 100, 350, 225, 67, 275, 165};

	// 2d array to store results
	int knapsack_values[7][46];
		
	// go through all possible number of items
	for (int num_items = 0; num_items <= max_items; num_items++) {

		// go through all possible weights
		for (int weight_limit = 0; weight_limit <= max_weight; weight_limit++) {

			// get best value for number of items and weight combination
			knapsack_values[num_items][weight_limit] = value(num_items, weight_limit, knapsack_values, item_weights, item_values);
		}
	}


	// print out knapsack_values array (./a.out > knapsack_values.txt)
	for (int num_items = 0; num_items <= max_items; num_items++) {
		for (int weight_limit = 0; weight_limit <= max_weight; weight_limit++) {
			std::cout << knapsack_values[num_items][weight_limit] << "\t\t\t";
		}
		std::cout << std::endl << std::endl;
	}

}

int value (int num_items, int weight_limit, int (&knapsack_values)[7][46], int (&item_weights)[7], int (&item_values)[7]) {
	int leave;
	int take; 

	// check if leave branch causes out of bounds num_items or if base case
	if (num_items - 1 < 0 || num_items == 0) {
		leave = 0;	
	}
	
	// if not, set leave branch value
	else {
		leave = knapsack_values[num_items - 1][weight_limit];
	}

	// check if take branch causes out of bounds weight_limit or if base case
	if (weight_limit - item_weights[num_items] < 0 || item_weights[num_items] == 0) {
		take = 0;
	} 

	// if not, set take branch value
	else {
		take = item_values[num_items] + value (num_items, weight_limit - item_weights[num_items], knapsack_values, item_values, item_weights);
	}

	return std::max(leave, take);
}


	