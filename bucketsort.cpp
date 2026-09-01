#include <iostream>
using namespace std;

void bucketSort(int arr[], int n)
{
    int bucket[10][10] = {0};
    int count[10] = {0};

    // Put elements into buckets
    for(int i = 0; i < n; i++)
    {
        int index = arr[i] / 10;

        bucket[index][count[index]] = arr[i];
        count[index]++;
    }

    // Sort each bucket
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < count[i] - 1; j++)
        {
            for(int k = j + 1; k < count[i]; k++)
            {
                if(bucket[i][j] > bucket[i][k])
                {
                    int temp = bucket[i][j];
                    bucket[i][j] = bucket[i][k];
                    bucket[i][k] = temp;
                }
            }
        }
    }

    // Put elements back into array
    int k = 0;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < count[i]; j++)
        {
            arr[k] = bucket[i][j];
            k++;
        }
    }
}

int main()
{
    int arr[] = {42, 23, 75, 12, 56, 91, 34};
    int n = 7;

    bucketSort(arr, n);

    cout << "Sorted array: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
