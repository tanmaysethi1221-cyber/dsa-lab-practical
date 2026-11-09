#include <iostream>
#include <vector>
using namespace std;
void binSort(int arr[], int size) {
 if (size <= 1)
 return;
 int minimum = arr[0];
 int maximum = arr[0];
 for (int i = 1; i < size; i++) {
 if (arr[i] < minimum)
 minimum = arr[i];
 if (arr[i] > maximum)
 maximum = arr[i];
 }
 vector<int> bins(maximum - minimum + 1, 0);
 for (int i = 0; i < size; i++)
 bins[arr[i] - minimum]++;
 int index = 0;
 for (int value = 0; value < static_cast<int>(bins.size()); value++) {
 while (bins[value] > 0) {
 arr[index] = value + minimum;
 index++;
 bins[value]--;
 }
 }
}
void printArray(const int arr[], int size) {
 for (int i = 0; i < size; i++)
 cout << arr[i] << " ";
 cout << '\n';
}
int main() {
 int arr[] = {42, 32, 33, 52, 37, 47, 51};
 int size = sizeof(arr) / sizeof(arr[0]);
 cout << "Before sorting:\n";
 printArray(arr, size);
 binSort(arr, size);
 cout << "After sorting:\n";
 printArray(arr, size);
 return 0;
}
