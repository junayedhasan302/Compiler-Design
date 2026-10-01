#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n; int arr[n];
    // Array Input
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int position, value;
    cout << "Enter Index: "; cin >> position;
    cout << "Enter value: "; cin >> value;
    // Right shift
    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    n++;
    // Output right shifted array
    cout << "Right shifted values: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // Output sorted array
    cout << "Sorted values: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}