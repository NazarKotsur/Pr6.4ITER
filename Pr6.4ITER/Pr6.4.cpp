#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

double findMinRecursive(double arr[], int n, int index = 0) {
    if (index == n - 1) {
        return arr[index];
    }

    double minInRest = findMinRecursive(arr, n, index + 1);
    return (arr[index] < minInRest) ? arr[index] : minInRest;
}

double findSumBetweenPositivesRecursive(double arr[], int n, int firstPositiveIndex = -1, int currentIndex = 0) {
    if (currentIndex == n) {
        return 0;
    }

    if (arr[currentIndex] > 0) {
        if (firstPositiveIndex == -1) {
            return findSumBetweenPositivesRecursive(arr, n, currentIndex, currentIndex + 1);
        }
        else {
            return arr[currentIndex - 1] + findSumBetweenPositivesRecursive(arr, n, firstPositiveIndex, currentIndex + 1);
        }
    }

    return findSumBetweenPositivesRecursive(arr, n, firstPositiveIndex, currentIndex + 1);
}

void moveZerosToFrontRecursive(double arr[], int n, int currentIndex = 0, int zeroCount = 0) {
    if (currentIndex == n) {
        return;
    }

    if (arr[currentIndex] == 0) {
        for (int i = currentIndex; i > zeroCount; i--) {
            swap(arr[i], arr[i - 1]);
        }
        zeroCount++;
    }

    moveZerosToFrontRecursive(arr, n, currentIndex + 1, zeroCount);
}

double* createArrayRecursive(int n, int currentIndex = 0) {
    if (currentIndex == n) {
        return new double[n];
    }

    double* arr = createArrayRecursive(n, currentIndex + 1);

    cout << "Enter element at index " << currentIndex << ": ";
    cin >> arr[currentIndex];

    return arr;
}

int main() {
    int n;

    do {
        cout << "Enter the size of the array: ";
        cin >> n;

        if (n <= 0) {
            cout << "Invalid size. Please enter a positive integer." << endl;
        }
    } while (n <= 0);

    double* arr = createArrayRecursive(n);

    cout << "\nOriginal array: ";
    for (int i = 0; i < n; i++) {
        cout << setw(3) << static_cast<int>(arr[i]) << " ";
    }

    moveZerosToFrontRecursive(arr, n);

    cout << "\nTransformed array: ";
    for (int i = 0; i < n; i++) {
        cout << setw(3) << static_cast<int>(arr[i]) << " ";
    }

    cout << "\nMinimum element in the array: " << static_cast<int>(findMinRecursive(arr, n));
    cout << "\nSum of elements between first and last positive elements: " << static_cast<int>(findSumBetweenPositivesRecursive(arr, n));

    // Звільнення пам'яті
    delete[] arr;

    return 0;
}
