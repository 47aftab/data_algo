#include <iostream>
#include <algorithm>
using namespace std;

void countSort(int inputArray[], int N) {
    int M = 0;

    for (int i = 0; i < N; i++)
        M = max(M, inputArray[i]);

    int countArray[M + 1] = {0};

    for (int i = 0; i < N; i++)
        countArray[inputArray[i]]++;

    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];

    int outputArray[N];

    for (int i = N - 1; i >= 0; i--) {
        outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
        countArray[inputArray[i]]--;
    }
    
    for (int i = 0; i < N; i++)
        inputArray[i] = outputArray[i];
}

void radixSort(int inputArray[], int N) {
    int maxElement = *max_element(inputArray, inputArray + N);
    
    for (int exp = 1; maxElement / exp > 0; exp *= 10)
        countSort(inputArray, N);
}

int main() {
    int size = 0;

    cout << "Enter the size of array: ";
    cin >> size;

    int inputArray[size];

    cout << "Enter the elements:\n";
    for (int i = 0; i < size; i++)
        cin >> inputArray[i];

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Sort and print the sorted array\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                radixSort(inputArray, size);
                cout << "Array sorted successfully.\n";
                cout << "Sorted Array: ";
                for (int i = 0; i < size; i++)
                    cout << inputArray[i] << " ";
                cout << endl;
                break;
            case 2:
                cout << "Exiting\n";
                break;
        }
    } while (choice != 2);
    return 0;
}
