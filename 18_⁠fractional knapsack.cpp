#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an item
struct Item {
    int value;
    int weight;
    // Constructor
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator function to sort items by value-to-weight ratio in descending order
bool compare(Item a, Item b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2;
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int W, vector<Item>& items, int n) {
    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;  // Total value of the knapsack
    int currentWeight = 0;    // Current weight in the knapsack

    for (int i = 0; i < n; i++) {
        // If adding the whole item doesn't exceed the capacity
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
        else {
            // Take the fraction of the remaining item that fits
            int remainingWeight = W - currentWeight;
            totalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int W, n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items;
    cout << "Enter the value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        int value, weight;
        cin >> value >> weight;
        items.push_back(Item(value, weight));
    }

    // Call the function to get the maximum value in the knapsack
    double maxValue = fractionalKnapsack(W, items, n);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
