#include <iostream>


using namespace std;

void PrintArray(const int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void InsertionSort(int* arr, int start, int end, bool descending)
{
    for (int i = start + 1; i < end; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= start &&
            (descending ? arr[j] < key : arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


void SortArray(int* arr, int size, bool descending = false)
{
    InsertionSort(arr, 0, size, descending);
}


void SortHalves(int* arr, int size)
{
    int middle = size / 2;

    InsertionSort(arr, 0, middle, true);
    InsertionSort(arr, middle, size, false);
}

void SortBetweenNegatives(int* arr, int size)
{
    int left = -1;
    int right = -1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            if (left == -1)
            {
                left = i;
            }

            right = i;
        }
    }

    if (left == -1 || left == right)
    {
        cout << "Not enough negative elements\n";
        return;
    }

    cout << "Left negative index: " << left << '\n';
    cout << "Right negative index: " << right << '\n';

    InsertionSort(arr, left + 1, right, false);
}

int main()
{
    srand(time(nullptr));

    const int SIZE = 10;

    // Task 1
    int arr1[SIZE] = { 8, 3, -5, 12, 0, 7, 2, -9, 15, 4 };

    cout << "Original: ";
    PrintArray(arr1, SIZE);

    SortArray(arr1, SIZE);
    cout << "Ascending: ";
    PrintArray(arr1, SIZE);

    SortArray(arr1, SIZE, true);
    cout << "Descending: ";
    PrintArray(arr1, SIZE);

    // Task 2
    int arr2[SIZE] = { 4, 9, 2, 7, 1, 8, 3, 6, 5, 0 };

    cout << "Original: ";
    PrintArray(arr2, SIZE);

    SortHalves(arr2, SIZE);

    cout << "Sorted halves: ";
    PrintArray(arr2, SIZE);

    // Task 3
    int arr3[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        arr3[i] = rand() % 41 - 20;
    }

    cout << "Original: ";
    PrintArray(arr3, SIZE);

    SortBetweenNegatives(arr3, SIZE);

    cout << "Result: ";
    PrintArray(arr3, SIZE);

    return 0;
}
