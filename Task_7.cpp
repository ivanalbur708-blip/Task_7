#include <iostream>


using namespace std;

bool Contains(const int* array, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value) return true;
    }
    return false;
}

void PrintArray(const int* array, int size)
{
    for (int i = 0; i < size; i++) cout << array[i] << ' ';
    cout << '\n';
}

int main()
{


    int sizeA;
    int sizeB;
    cout << "Enter sizes M and N: ";
    cin >> sizeA >> sizeB;

    int* arrayA = new int[sizeA];
    int* arrayB = new int[sizeB];
    cout << "Enter array A: ";
    for (int i = 0; i < sizeA; i++) cin >> arrayA[i];
    cout << "Enter array B: ";
    for (int i = 0; i < sizeB; i++) cin >> arrayB[i];

    // Task 1
    int mergedSize = sizeA + sizeB;
    int* merged = new int[mergedSize];
    for (int i = 0; i < sizeA; i++) merged[i] = arrayA[i];
    for (int i = 0; i < sizeB; i++) merged[sizeA + i] = arrayB[i];

    cout << "Merged array: ";
    PrintArray(merged, mergedSize);

    // Task 2
    int commonSize = 0;
    for (int i = 0; i < sizeA; i++)
    {
        if (Contains(arrayB, sizeB, arrayA[i]))
        {
            bool alreadyCounted = false;
            for (int j = 0; j < i; j++)
            {
                if (arrayA[j] == arrayA[i]) alreadyCounted = true;
            }
            if (!alreadyCounted) commonSize++;
        }
    }

    int* common = new int[commonSize];
    int commonIndex = 0;
    for (int i = 0; i < sizeA; i++)
    {
        if (Contains(arrayB, sizeB, arrayA[i]) && !Contains(common, commonIndex, arrayA[i]))
        {
            common[commonIndex++] = arrayA[i];
        }
    }

    cout << "Common elements: ";
    PrintArray(common, commonSize);

    // Task 3
    int removeChoice;
    cout << "1 - remove even, 2 - remove odd: ";
    cin >> removeChoice;

    int filteredSize = 0;
    for (int i = 0; i < sizeA; i++)
    {
        bool remove = removeChoice == 1 ? arrayA[i] % 2 == 0 : arrayA[i] % 2 != 0;
        if (!remove) filteredSize++;
    }

    int* filtered = new int[filteredSize];
    int filteredIndex = 0;
    for (int i = 0; i < sizeA; i++)
    {
        bool remove = removeChoice == 1 ? arrayA[i] % 2 == 0 : arrayA[i] % 2 != 0;
        if (!remove) filtered[filteredIndex++] = arrayA[i];
    }

    cout << "Filtered array: ";
    PrintArray(filtered, filteredSize);

    delete[] arrayA;
    delete[] arrayB;
    delete[] merged;
    delete[] common;
    delete[] filtered;

    return 0;
}
