#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

int main() {
    vector<int> numbers;

    for (int i = 100; i > 0; --i) {
        numbers.push_back(i);
    }

    auto startTimeBubbleSort = chrono::high_resolution_clock::now();

    for (int i = 0; i < numbers.size(); ++i) {
        for (int j = 0; j < numbers.size() - i - 1; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }
    auto endTimeBubbleSort = chrono::high_resolution_clock::now();

    auto durationBubbleSort = chrono::duration_cast<chrono::microseconds>(endTimeBubbleSort - startTimeBubbleSort);

    cout << "Bubble Sort Proper Execution Time: " << durationBubbleSort.count() << " microseconds\n";

    numbers.clear();

    for (int i = 100000; i > 0; --i) {
        numbers.push_back(i);
    }

    auto startTimeSTLSort = chrono::high_resolution_clock::now();

    sort(numbers.begin(), numbers.end());

    auto endTimeSTLSort = chrono::high_resolution_clock::now();

    auto durationSTLSort = chrono::duration_cast<chrono::microseconds>(endTimeSTLSort - startTimeSTLSort);

    cout << "STL Sort Execution Time: " << durationSTLSort.count() << " microseconds\n";

    return 0;
}
