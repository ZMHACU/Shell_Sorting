#include<iostream>
using namespace std;

void printArray(int arr[], int n, int gap, int j, int i) {
    for (int k = 0; k < n; k++) {
        if (k == j) cout << "[" << arr[k] << "] ";  // Mark current element
        else if (k == i) cout << "{" << arr[k] << "} ";  // Mark compared element
        else cout << arr[k] << " ";
    }
    cout << " (Gap=" << gap << ")";
    cout << endl;
}

void ShellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        cout << "\n--- Gap = " << gap << " ---" << endl;
        for (int j = gap; j < n; j++) {
            int temp = arr[j];
            int i = j;
            
            cout << "\nChecking element at index " << j << " (Value=" << arr[j] << "):" << endl;
            printArray(arr, n, gap, j, -1);  // Show array before comparison
            
            while (i >= gap && arr[i - gap] > temp) {
                cout << "  Swap " << arr[i - gap] << " (index " << i - gap 
                     << ") with " << arr[i] << " (index " << i << ")" << endl;
                
                arr[i] = arr[i - gap];
                i -= gap;
                
                printArray(arr, n, gap, j, i);  // Show array after swap
            }
            
            if (arr[i] != temp) {
                cout << "  Insert " << temp << " at index " << i << endl;
                arr[i] = temp;
                printArray(arr, n, gap, -1, i);  // Show final insertion
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr1[n];

    cout << "Enter " << n << " integers in any order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "\nBefore Sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }

    cout << "\n\nSHELL SORT STEP-BY-STEP:\n";
    ShellSort(arr1, n);

    cout << "\nAfter Sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    return 0;
}