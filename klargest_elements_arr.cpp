
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

void kLargest(int arr[], int n, int k) {
    int low = 0, high = n - 1;
    int target = n - k;

    while (low <= high) {
        int p = partition(arr, low, high);

        if (p == target)
            break;
        else if (p < target)
            low = p + 1;
        else
            high = p - 1;
    }

    cout << "K largest elements: ";
    for (int i = n - k; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int arr[] = {10, 5, 20, 8, 30, 15};
    int n = 6, k = 3;

    kLargest(arr, n, k);
    return 0;
}
