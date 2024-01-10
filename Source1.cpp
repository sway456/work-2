#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void addProduct(vector<int>& inventory, int productId) {
    inventory.push_back(productId);
}

void removeProduct(vector<int>& inventory, int productId) {
    auto it = remove(inventory.begin(), inventory.end(), productId);
    inventory.erase(it, inventory.end());
}

int main() {
    vector<int> inventory;

    
    addProduct(inventory, 100);
    addProduct(inventory, 101);
    addProduct(inventory, 102);

    removeProduct(inventory, 101);

    cout << "After operations: ";
    for (const auto& product : inventory) {
        cout << product << " ";
    }

    cout << "\n";

    return 0;
}