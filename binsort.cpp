#include <iostream>

using namespace std;

void binSort(int arr[], int n) {
    // 1. Find the maximum element
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // 2. Create frequency bins initialized to 0
    int count[maxVal + 1] = {0};

    // 3. Put each number into its bin
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 4. Put elements back into the array in sorted order
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    int arr[] = {9, 3, 1, 5, 2, 8, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    binSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
